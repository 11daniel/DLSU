#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""
SAM Hive Parser – Final Reliable Version with Field Mapping
NSSECU3 Mini Project 3
Author: GROUP 7
Date: March 2026

Implements:
- Registry header parsing
- HBIN enumeration
- NK record parsing with sanity checks
- Subkey list parsing (lf, lh, li, ri)
- VK record parsing with strict validation
- Fallback scanning for VK records when value list is suspicious
- Recursive tree traversal from root
- Automatic extraction of user account data (F and V values)
- Authoritative username source: SAM\Domains\Account\Users\Names
- Hex dump output for manual Excel mapping
- CSV export of parsed user data (including hash candidates)
- **Field‑level offset mapping** for Excel colour coding
"""

import sys
import struct
import csv
from datetime import datetime, timedelta

# ----------------------------------------------------------------------
# Constants
# ----------------------------------------------------------------------
REGF_MAGIC = b"regf"
HBIN_MAGIC = b"hbin"
NK_MAGIC = b"nk"
VK_MAGIC = b"vk"
LIST_MAGICS = {b'lf', b'lh', b'li', b'ri'}

FIRST_HBIN_ABS = 0x1000

# Registry value types (for display only)
REG_TYPES = {
    0: "REG_NONE", 1: "REG_SZ", 2: "REG_EXPAND_SZ", 3: "REG_BINARY",
    4: "REG_DWORD", 5: "REG_DWORD_BIG_ENDIAN", 6: "REG_LINK",
    7: "REG_MULTI_SZ", 8: "REG_RESOURCE_LIST", 9: "REG_FULL_RESOURCE_DESCRIPTOR",
    10: "REG_RESOURCE_REQUIREMENTS_LIST", 11: "REG_QWORD",
}

# Account flags (from Windows SDK)
UF_ACCOUNT_DISABLE = 0x00000002
UF_LOCKOUT = 0x00000010
UF_PASSWD_NOTREQD = 0x00000020
UF_PASSWD_CANT_CHANGE = 0x00000040
UF_NORMAL_ACCOUNT = 0x00000200
UF_DONT_EXPIRE_PASSWD = 0x00010000
UF_PASSWORD_EXPIRED = 0x00800000

# ----------------------------------------------------------------------
# Helper functions
# ----------------------------------------------------------------------
def u16(data, off): return struct.unpack_from("<H", data, off)[0]
def u32(data, off): return struct.unpack_from("<I", data, off)[0]
def i32(data, off): return struct.unpack_from("<i", data, off)[0]
def u64(data, off): return struct.unpack_from("<Q", data, off)[0]

def filetime_to_str(ft):
    if ft == 0 or ft == 0x7FFFFFFFFFFFFFFF:
        return "N/A"
    try:
        dt = datetime(1601, 1, 1) + timedelta(microseconds=ft / 10)
        return dt.strftime("%Y-%m-%d %H:%M:%S")
    except Exception:
        return str(ft)

def is_printable_ascii(bs):
    return bool(bs) and all(0x20 <= b <= 0x7E for b in bs)

def decode_name(raw):
    if not raw:
        return ""
    if is_printable_ascii(raw):
        return raw.decode("ascii", errors="ignore")
    try:
        s = raw.decode("utf-16le", errors="ignore").rstrip("\x00")
        if s and any(ch.isalnum() for ch in s):
            return s
    except Exception:
        pass
    return raw.decode("ascii", errors="ignore").rstrip("\x00")

def rel_to_abs(rel_off):
    if rel_off == 0xFFFFFFFF or rel_off == 0:
        return None
    return FIRST_HBIN_ABS + rel_off

def hex_dump(data, label="", start=0, length=None):
    """Print a classic hex dump with ASCII column for manual Excel mapping."""
    if length is None:
        length = len(data)
    print(f"\n{label} (offset 0x{start:04x}):")
    print("Offset  00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F  ASCII")
    for i in range(0, length, 16):
        chunk = data[i:i+16]
        hex_part = ' '.join(f"{b:02x}" for b in chunk)
        ascii_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
        print(f"{start+i:04x}    {hex_part:<47} {ascii_part}")

def entropyish(blob):
    """Simple heuristic: number of unique bytes."""
    return len(set(blob))

# ----------------------------------------------------------------------
# Automatic parsing functions
# ----------------------------------------------------------------------
def auto_find_utf16_string(data, target=None, min_len=3, max_len=64):
    """
    Find a UTF‑16LE string in data.
    If target is provided, search for its exact UTF‑16LE representation.
    Otherwise, return the first plausible string.
    Returns (start_offset, length_in_chars, string) or (None,0,None).
    """
    if target:
        # Try with null terminator
        target_bytes = target.encode("utf-16le") + b"\x00\x00"
        pos = data.find(target_bytes)
        if pos != -1:
            return pos, len(target), target
        # Try without null terminator
        target_bytes = target.encode("utf-16le")
        pos = data.find(target_bytes)
        if pos != -1:
            return pos, len(target), target
        return None, 0, None

    # Fallback: find first plausible string
    for i in range(0, len(data) - 2, 2):
        if data[i+1] == 0x00 and 0x20 <= data[i] <= 0x7E:
            j = i
            while j+1 < len(data) and data[j+1] == 0x00 and 0x20 <= data[j] <= 0x7E:
                j += 2
            length = (j - i) // 2
            if min_len <= length <= max_len:
                s = data[i:j+2].decode("utf-16le", errors="ignore").rstrip("\x00")
                return i, length, s
    return None, 0, None

def auto_parse_v(v_data, expected_username=None):
    """
    Extract username and hash blobs from V value data using the structured V header.

    The V value binary layout (all offsets relative to start of v_data which
    includes the 4-byte cell-size prefix):

        v_data[0:4]          – cell size (negative int32, skip it)
        v_data[4:]           – V payload (the actual SAM_USER_ACCOUNT_V struct)

    Within the V payload, each user-data field is described by a 12-byte entry
    (offset DWORD, length DWORD, type DWORD).  The table starts at V_payload+0x00
    and data strings are stored at  V_payload + 0xCC + field_offset.

    Entry positions in the header table (relative to V_payload start):
        +0x0C  username   (offset + length + type)
        +0x90  LM hash    (offset + length + type)
        +0x9C  NT hash    (offset + length + type)

    Returns dict: username, username_offset, lm_blob, nt_blob,
                  lm_offset, nt_offset  (all *absolute within v_data*).
    """
    # v_data includes the 4-byte cell header; V payload starts at offset 4
    V_HDR  = 4        # bytes to skip for cell header
    V_BASE = V_HDR + 0xCC   # base of the string/hash data area within v_data

    result = {
        "username": "",
        "username_offset": None,
        "lm_blob": b"",
        "nt_blob": b"",
        "lm_offset": None,
        "nt_offset": None,
    }

    # Minimum size check: need at least up to the NT-hash entry (+0x9C+12 = 0xA8)
    if len(v_data) < V_HDR + 0xA8:
        return None

    # ── Username (entry at V_payload+0x0C) ──────────────────────────────────
    usr_off = u32(v_data, V_HDR + 0x0C)   # relative offset inside data area
    usr_len = u32(v_data, V_HDR + 0x10)   # byte length of the UTF-16LE string

    if 0 < usr_len <= 512:
        ustart = V_BASE + usr_off
        if ustart + usr_len <= len(v_data):
            uname = v_data[ustart:ustart + usr_len].decode("utf-16le",
                                                            errors="ignore")
            result["username"] = uname
            result["username_offset"] = ustart

    if not result["username"]:
        return None   # no usable username → skip this record

    # ── LM hash blob (entry at V_payload+0x90) ──────────────────────────────
    lm_off = u32(v_data, V_HDR + 0x90)
    lm_len = u32(v_data, V_HDR + 0x94)
    if 0 < lm_len <= 64:
        lstart = V_BASE + lm_off
        if lstart + lm_len <= len(v_data):
            result["lm_blob"]   = v_data[lstart:lstart + lm_len]
            result["lm_offset"] = lstart

    # ── NT hash blob (entry at V_payload+0x9C) ──────────────────────────────
    nt_off = u32(v_data, V_HDR + 0x9C)
    nt_len = u32(v_data, V_HDR + 0xA0)
    if 0 < nt_len <= 64:
        nstart = V_BASE + nt_off
        if nstart + nt_len <= len(v_data):
            result["nt_blob"]   = v_data[nstart:nstart + nt_len]
            result["nt_offset"] = nstart

    return result

def auto_parse_f_improved(f_data, expected_rid):
    """
    Parse the F value using known structure of USER_ACCOUNT.
    Returns a dict with account flags, timestamps, etc., including offsets.
    """
    rid_bytes = struct.pack("<I", expected_rid)
    rid_off = None
    for off in range(len(f_data) - 3):
        if f_data[off:off+4] == rid_bytes:
            rid_off = off
            break
    if rid_off is None or rid_off < 0x30:
        return None

    struct_start = rid_off - 0x30  # approximate start of USER_ACCOUNT

    def get_dword(off):
        if struct_start + off + 4 <= len(f_data):
            return u32(f_data, struct_start + off)
        return 0
    def get_qword(off):
        if struct_start + off + 8 <= len(f_data):
            return u64(f_data, struct_start + off)
        return 0

    last_logon        = get_qword(0x08)   # payload+0x08  LastLogon FILETIME
    # payload+0x10 = LastLogoff (not displayed)
    last_pwd_set      = get_qword(0x18)   # payload+0x18  PasswordLastSet FILETIME
    account_expires   = get_qword(0x20)   # payload+0x20  AccountExpires FILETIME
    last_failed_logon = get_qword(0x28)   # payload+0x28  LastBadPasswordTime FILETIME
    # payload+0x30 = RID (anchor used above)
    # payload+0x34 = PrimaryGroupId  (NOT logon count!)
    # payload+0x38 = ACB flags
    # payload+0x3C = CountryCode (WORD) + CodePage (WORD)
    # payload+0x40 = BadPasswordCount (WORD)
    # payload+0x42 = LogonCount (WORD)
    rid                = get_dword(0x30)
    account_flags      = get_dword(0x38)   # ACB flags at +0x38
    failed_logon_count = struct.unpack_from("<H", f_data, struct_start + 0x40)[0]
    logon_count        = struct.unpack_from("<H", f_data, struct_start + 0x42)[0]

    # SAM ACB flag bit definitions (different from UF_ constants used in AD/LDAP)
    ACB_DISABLED   = 0x0001   # Account Disabled
    ACB_HOMEDIR    = 0x0002   # Home Directory Required
    ACB_PASSWD_NR  = 0x0004   # Password Not Required
    ACB_TEMP_DUP   = 0x0008   # Temp Duplicate Account
    ACB_NORMAL     = 0x0010   # Normal User Account
    ACB_MNS        = 0x0020   # MNS Logon Account
    ACB_DOMTRUST   = 0x0040   # Interdomain Trust Account
    ACB_WSTRUST    = 0x0080   # Workstation Trust Account
    ACB_SVRTRUST   = 0x0100   # Server Trust Account
    ACB_PWNOEXP    = 0x0200   # Password Does Not Expire
    ACB_AUTOLOCK   = 0x0400   # Account Auto Locked

    flags_list = []
    if account_flags & ACB_DISABLED:  flags_list.append("DISABLED")
    if account_flags & ACB_HOMEDIR:   flags_list.append("HOMEDIR_REQUIRED")
    if account_flags & ACB_PASSWD_NR: flags_list.append("PASSWORD_NOT_REQUIRED")
    if account_flags & ACB_TEMP_DUP:  flags_list.append("TEMP_DUPLICATE")
    if account_flags & ACB_NORMAL:    flags_list.append("NORMAL_ACCOUNT")
    if account_flags & ACB_MNS:       flags_list.append("MNS_LOGON")
    if account_flags & ACB_DOMTRUST:  flags_list.append("INTERDOMAIN_TRUST")
    if account_flags & ACB_WSTRUST:   flags_list.append("WORKSTATION_TRUST")
    if account_flags & ACB_SVRTRUST:  flags_list.append("SERVER_TRUST")
    if account_flags & ACB_PWNOEXP:   flags_list.append("PASSWORD_NEVER_EXPIRES")
    if account_flags & ACB_AUTOLOCK:  flags_list.append("AUTO_LOCKED")

    return {
        "rid": rid,
        "account_flags": account_flags,
        "flags_readable": ", ".join(flags_list) if flags_list else "None",
        "last_logon": filetime_to_str(last_logon),
        "last_pwd_set": filetime_to_str(last_pwd_set),
        "account_expires": filetime_to_str(account_expires),
        "last_failed_logon": filetime_to_str(last_failed_logon),
        "failed_logon_count": failed_logon_count,
        "logon_count": logon_count,
        "offsets": {
            "struct_start": struct_start,
            "rid":               rid_off,
            "flags":             struct_start + 0x38,
            "last_logon":        struct_start + 0x08,
            "last_pwd_set":      struct_start + 0x18,
            "account_expires":   struct_start + 0x20,
            "last_failed_logon": struct_start + 0x28,
            "failed_logon_count":struct_start + 0x40,
            "logon_count":       struct_start + 0x42,
        }
    }

# ----------------------------------------------------------------------
# Data structures
# ----------------------------------------------------------------------
class NKRecord:
    def __init__(self, abs_off, rel_off, parent_rel, name, flags,
                 subkey_count, subkey_list_rel, value_count, value_list_rel, timestamp):
        self.abs_off = abs_off
        self.rel_off = rel_off
        self.parent_rel = parent_rel
        self.name = name
        self.flags = flags
        self.subkey_count = subkey_count
        self.subkey_list_rel = subkey_list_rel
        self.value_count = value_count
        self.value_list_rel = value_list_rel
        self.timestamp = timestamp

class VKRecord:
    def __init__(self, abs_off, rel_off, name, value_type, data_len, data_rel, inline, data):
        self.abs_off = abs_off
        self.rel_off = rel_off
        self.name = name
        self.value_type = value_type
        self.data_len = data_len
        self.data_rel = data_rel
        self.inline = inline
        self.data = data

# ----------------------------------------------------------------------
# Main parser class
# ----------------------------------------------------------------------
class SAMParser:
    def __init__(self, path):
        self.path = path
        with open(path, "rb") as f:
            self.data = f.read()
        self.hbins = []
        self.nk_by_abs = {}
        self.root_abs = None

    # ------------------------------------------------------------------
    # Header and HBIN enumeration
    # ------------------------------------------------------------------
    def parse_header(self):
        if self.data[0:4] != REGF_MAGIC:
            raise ValueError("Not a valid registry hive (missing regf)")

        seq1 = u32(self.data, 0x04)
        seq2 = u32(self.data, 0x08)
        last_write_ft = u64(self.data, 0x0C)
        major = u32(self.data, 0x14)
        minor = u32(self.data, 0x18)
        root_cell_rel = u32(self.data, 0x24)
        hive_bins_size = u32(self.data, 0x28)

        self.root_abs = root_cell_rel + FIRST_HBIN_ABS

        print("[*] Registry hive header")
        print(f"    Magic         : {self.data[0:4].decode(errors='ignore')}")
        print(f"    Sequence      : {seq1}:{seq2}")
        print(f"    Last write    : {filetime_to_str(last_write_ft)}")
        print(f"    Version       : {major}.{minor}")
        print(f"    Root cell rel : 0x{root_cell_rel:08X}")
        print(f"    Root cell abs : 0x{self.root_abs:08X}")
        print(f"    HBIN area size: 0x{hive_bins_size:08X}")

    def parse_hbins(self):
        print("\n[*] Enumerating HBIN blocks")
        off = FIRST_HBIN_ABS
        while off + 0x20 <= len(self.data):
            if self.data[off:off + 4] != HBIN_MAGIC:
                break
            rel = u32(self.data, off + 0x04)
            size = u32(self.data, off + 0x08)
            if size == 0:
                break
            self.hbins.append((off, rel, size))
            off += size
        print(f"[*] Found {len(self.hbins)} HBIN block(s)")
        for i, (abs_off, rel, size) in enumerate(self.hbins):
            print(f"    HBIN[{i}] abs=0x{abs_off:08X} rel=0x{rel:08X} size=0x{size:08X}")

    # ------------------------------------------------------------------
    # NK record parsing
    # ------------------------------------------------------------------
    def try_parse_nk(self, cell_abs):
        try:
            cell_size = i32(self.data, cell_abs)
            if cell_size >= 0:
                return None
            if self.data[cell_abs + 4:cell_abs + 6] != NK_MAGIC:
                return None

            flags = u16(self.data, cell_abs + 0x06)
            timestamp = u64(self.data, cell_abs + 0x08)
            parent_rel = u32(self.data, cell_abs + 0x14)
            subkey_count = u32(self.data, cell_abs + 0x18)
            subkey_list_rel = u32(self.data, cell_abs + 0x20)
            # +0x24 = volatile subkey list (always 0xFFFFFFFF if none) — NOT value_count
            # +0x28 = actual value count,  +0x2C = value list relative offset
            value_count = u32(self.data, cell_abs + 0x28)
            value_list_rel = u32(self.data, cell_abs + 0x2C)

            name_len = u16(self.data, cell_abs + 0x4C)
            name_start = cell_abs + 0x50
            name_end = name_start + name_len
            if name_end > len(self.data):
                return None
            raw_name = self.data[name_start:name_end]
            name = decode_name(raw_name).strip()

            rel_off = cell_abs - FIRST_HBIN_ABS
            return NKRecord(
                abs_off=cell_abs,
                rel_off=rel_off,
                parent_rel=parent_rel,
                name=name,
                flags=flags,
                subkey_count=subkey_count,
                subkey_list_rel=subkey_list_rel,
                value_count=value_count,
                value_list_rel=value_list_rel,
                timestamp=timestamp,
            )
        except Exception:
            return None

    def scan_nks(self):
        print("\n[*] Scanning HBIN cells for NK records")
        for hbin_abs, _, hbin_size in self.hbins:
            cell = hbin_abs + 0x20
            hbin_end = hbin_abs + hbin_size
            while cell + 4 <= hbin_end and cell + 4 <= len(self.data):
                try:
                    raw_size = i32(self.data, cell)
                except Exception:
                    break
                if raw_size == 0:
                    break
                step = abs(raw_size)
                if step < 4:
                    break
                nk = self.try_parse_nk(cell)
                if nk:
                    self.nk_by_abs[cell] = nk
                cell += step
        print(f"[*] Total NK records found: {len(self.nk_by_abs)}")

    # ------------------------------------------------------------------
    # Subkey list parsing
    # ------------------------------------------------------------------
    def parse_subkey_list(self, offset_rel, count):
        offset_abs = rel_to_abs(offset_rel)
        if offset_abs is None or offset_abs + 4 > len(self.data):
            return []
        magic = self.data[offset_abs + 4:offset_abs + 6]

        if magic not in LIST_MAGICS:
            offsets = []
            for i in range(count):
                off = u32(self.data, offset_abs + 8 + i * 4)
                if off == 0:
                    break
                nk_abs = rel_to_abs(off)
                if nk_abs:
                    offsets.append(nk_abs)
            return offsets

        if magic == b'ri':
            num_lists = u32(self.data, offset_abs + 8)
            offsets = []
            for i in range(num_lists):
                list_rel = u32(self.data, offset_abs + 12 + i * 4)
                offsets.extend(self.parse_subkey_list(list_rel, 0))
            return offsets

        entries = []
        for i in range(count):
            entry_off = offset_abs + 8 + i * 8
            if entry_off + 4 > len(self.data):
                break
            nk_rel = u32(self.data, entry_off)
            if nk_rel == 0:
                break
            nk_abs = rel_to_abs(nk_rel)
            if nk_abs:
                entries.append(nk_abs)
        return entries

    # ------------------------------------------------------------------
    # Tree traversal
    # ------------------------------------------------------------------
    def get_key_path(self, nk):
        parts = []
        cur = nk
        seen = set()
        while cur is not None:
            if cur.rel_off in seen:
                break
            seen.add(cur.rel_off)
            if cur.parent_rel == 0 or cur.parent_rel == 0xFFFFFFFF:
                if cur.abs_off == self.root_abs:
                    parts.append("ROOT")
                else:
                    parts.append(f"[UNKNOWN_ROOT_{cur.rel_off:08X}]")
                break
            else:
                parts.append(cur.name)
                parent_abs = rel_to_abs(cur.parent_rel)
                cur = self.nk_by_abs.get(parent_abs, None)
                if cur is None:
                    break
        return "\\".join(reversed(parts))

    def find_key_by_path(self, path):
        parts = path.split('\\')
        if parts[0] != "ROOT":
            return None
        current_nk = self.nk_by_abs.get(self.root_abs)
        if not current_nk:
            return None
        for part in parts[1:]:
            if current_nk.subkey_count == 0:
                return None
            child_offsets = self.parse_subkey_list(current_nk.subkey_list_rel, current_nk.subkey_count)
            found = False
            for child_abs in child_offsets:
                child = self.nk_by_abs.get(child_abs)
                if child and child.name == part:
                    current_nk = child
                    found = True
                    break
            if not found:
                return None
        return current_nk

    # ------------------------------------------------------------------
    # VK record parsing with strict validation
    # ------------------------------------------------------------------
    def parse_vk(self, vk_abs):
        try:
            cell_size = i32(self.data, vk_abs)
            if cell_size >= 0:
                return None
            if self.data[vk_abs + 4:vk_abs + 6] != VK_MAGIC:
                return None
            name_len = u16(self.data, vk_abs + 0x06)
            if name_len > 512:
                return None
            data_len_raw = u32(self.data, vk_abs + 0x08)
            data_rel = u32(self.data, vk_abs + 0x0C)
            value_type = u32(self.data, vk_abs + 0x10)
            flags = u16(self.data, vk_abs + 0x14)

            name_start = vk_abs + 0x18
            name_end = name_start + name_len
            if name_end > len(self.data):
                return None
            raw_name = self.data[name_start:name_end]

            if flags & 0x0001:
                name = raw_name.decode("ascii", errors="ignore").rstrip("\x00")
            else:
                name = decode_name(raw_name)

            inline = bool(data_len_raw & 0x80000000)
            data_len = data_len_raw & 0x7FFFFFFF

            data = b""
            if inline:
                data = struct.pack("<I", data_rel)[:data_len]
            else:
                data_abs = rel_to_abs(data_rel)
                if data_abs is not None and data_len > 0 and data_abs + data_len <= len(self.data):
                    data = self.data[data_abs:data_abs + data_len]
                else:
                    data = b""

            rel_off = vk_abs - FIRST_HBIN_ABS
            return VKRecord(
                abs_off=vk_abs,
                rel_off=rel_off,
                name=name,
                value_type=value_type,
                data_len=data_len,
                data_rel=data_rel,
                inline=inline,
                data=data,
            )
        except Exception:
            return None

    def scan_vk_near_nk(self, nk, max_bytes=0x200):
        """Scan for VK records starting just after the NK cell."""
        vks = []
        cell_size = abs(i32(self.data, nk.abs_off))
        start = nk.abs_off + cell_size
        end = min(start + max_bytes, len(self.data))
        pos = start
        while pos + 8 < end:
            cell_sz = i32(self.data, pos)
            if cell_sz == 0:
                break
            if cell_sz < 0 and self.data[pos+4:pos+6] == VK_MAGIC:
                vk = self.parse_vk(pos)
                if vk:
                    vks.append(vk)
            pos += abs(cell_sz)
        return vks

    def get_vk_list(self, nk):
        vks = []
        # With corrected NK offsets, value_count is now accurate.
        # Keep the guard for genuinely corrupt hives (threshold raised to 128).
        if nk.value_count > 128 or nk.value_count == 4294967295:
            print(f"    [!] Suspicious value_count={nk.value_count}, scanning nearby...")
            return self.scan_vk_near_nk(nk)

        if nk.value_count == 0 or nk.value_list_rel in (0, 0xFFFFFFFF):
            return vks

        list_abs = rel_to_abs(nk.value_list_rel)
        if list_abs is None:
            return vks

        for i in range(nk.value_count):
            # +4 to skip the 4-byte cell-size header that precedes the pointer array
            off_pos = list_abs + 4 + i * 4
            if off_pos + 4 > len(self.data):
                break
            vk_rel = u32(self.data, off_pos)
            if vk_rel == 0xFFFFFFFF:
                continue
            vk_abs = rel_to_abs(vk_rel)
            if vk_abs is None:
                continue
            vk = self.parse_vk(vk_abs)
            if vk:
                vks.append(vk)
        return vks

    # ------------------------------------------------------------------
    # Map RID to username from Names subkey (authoritative)
    # ------------------------------------------------------------------
    def map_rid_to_username(self):
        r"""Return dict {rid: username} from SAM\Domains\Account\Users\Names."""
        mapping = {}
        names_nk = self.find_key_by_path("ROOT\\SAM\\Domains\\Account\\Users\\Names")
        if not names_nk:
            return mapping
        name_offsets = self.parse_subkey_list(names_nk.subkey_list_rel, names_nk.subkey_count)
        for off in name_offsets:
            name_nk = self.nk_by_abs.get(off)
            if not name_nk:
                continue
            # The default value contains the RID (binary DWORD)
            vks = self.get_vk_list(name_nk)
            for vk in vks:
                # In SAM Names subkeys the default value's TYPE field holds the RID
                # (data_len is 0 / inline flag set; actual type encodes the RID integer)
                if vk.name == "":
                    rid = vk.value_type   # overloaded: type == RID
                    if rid > 0:
                        mapping[rid] = name_nk.name
                    break
        return mapping

    # ------------------------------------------------------------------
    # New methods for field mapping
    # ------------------------------------------------------------------
    def _get_bytes_hex(self, abs_off, length):
        """Return a hex string of `length` bytes starting at `abs_off`."""
        if abs_off + length > len(self.data):
            return "(out of range)"
        return ' '.join(f"{b:02x}" for b in self.data[abs_off:abs_off+length])

    def _print_field_mapping(self, rid, username, nk_abs, f_abs, f_info, v_abs, v_info):
        """Print a nicely formatted table of absolute offsets for key fields."""
        print("\n" + "="*60)
        print(f"FIELD MAPPING FOR RID {rid} ({username})")
        print("="*60)
        print(f"{'Field':<25} {'Abs Offset':<12} {'Bytes (hex)':<50}")
        print("-"*90)

        # NK record (key)
        print(f"{'NK record start':<25} {f'0x{nk_abs:04X}':<12} {self._get_bytes_hex(nk_abs, 4)} ...")
        # NK timestamp (at +0x08)
        ts_abs = nk_abs + 0x08
        print(f"{'  NK timestamp':<25} {f'0x{ts_abs:04X}':<12} {self._get_bytes_hex(ts_abs, 8)}")

        # F value data
        print(f"{'F value start':<25} {f'0x{f_abs:04X}':<12} {self._get_bytes_hex(f_abs, 4)} ...")
        # Cell size (first 4 bytes of F)
        print(f"{'  Cell size':<25} {f'0x{f_abs:04X}':<12} {self._get_bytes_hex(f_abs, 4)}")
        if f_info:
            off = f_info['offsets']
            # RID
            rid_abs = f_abs + off['rid']
            print(f"{'  RID':<25} {f'0x{rid_abs:04X}':<12} {self._get_bytes_hex(rid_abs, 4)}")
            # Flags
            flags_abs = f_abs + off['flags']
            print(f"{'  Flags':<25} {f'0x{flags_abs:04X}':<12} {self._get_bytes_hex(flags_abs, 4)}")
            # Timestamps
            last_logon_abs = f_abs + off['last_logon']
            print(f"{'  Last logon':<25} {f'0x{last_logon_abs:04X}':<12} {self._get_bytes_hex(last_logon_abs, 8)}")
            last_pwd_abs = f_abs + off['last_pwd_set']
            print(f"{'  Last pwd set':<25} {f'0x{last_pwd_abs:04X}':<12} {self._get_bytes_hex(last_pwd_abs, 8)}")
            expires_abs = f_abs + off['account_expires']
            print(f"{'  Account expires':<25} {f'0x{expires_abs:04X}':<12} {self._get_bytes_hex(expires_abs, 8)}")
            last_fail_abs = f_abs + off['last_failed_logon']
            print(f"{'  Last failed logon':<25} {f'0x{last_fail_abs:04X}':<12} {self._get_bytes_hex(last_fail_abs, 8)}")
            fail_count_abs = f_abs + off['failed_logon_count']
            print(f"{'  Failed logon count':<25} {f'0x{fail_count_abs:04X}':<12} {self._get_bytes_hex(fail_count_abs, 4)}")
            logon_count_abs = f_abs + off['logon_count']
            print(f"{'  Logon count':<25} {f'0x{logon_count_abs:04X}':<12} {self._get_bytes_hex(logon_count_abs, 4)}")

        # V value data
        print(f"{'V value start':<25} {f'0x{v_abs:04X}':<12} {self._get_bytes_hex(v_abs, 4)} ...")
        print(f"{'  Cell size':<25} {f'0x{v_abs:04X}':<12} {self._get_bytes_hex(v_abs, 4)}")
        if v_info and v_info['username_offset'] is not None:
            user_abs = v_abs + v_info['username_offset']
            # Show up to 16 bytes of username
            user_len = min(16, len(v_info['username'])*2)
            print(f"{'  Username':<25} {f'0x{user_abs:04X}':<12} {self._get_bytes_hex(user_abs, user_len)} ...")
        if v_info and v_info['lm_offset'] is not None:
            lm_abs = v_abs + v_info['lm_offset']
            print(f"{'  LM hash (candidate)':<25} {f'0x{lm_abs:04X}':<12} {self._get_bytes_hex(lm_abs, 16)}")
        if v_info and v_info['nt_offset'] is not None:
            nt_abs = v_abs + v_info['nt_offset']
            print(f"{'  NT hash (candidate)':<25} {f'0x{nt_abs:04X}':<12} {self._get_bytes_hex(nt_abs, 16)}")
        print("="*60 + "\n")

    # ------------------------------------------------------------------
    # User extraction (main) – modified to call mapping
    # ------------------------------------------------------------------
    def extract_users(self):
        print("\n[*] Extracting user account data from SAM\\Domains\\Account\\Users")
        users_nk = self.find_key_by_path("ROOT\\SAM\\Domains\\Account\\Users")
        if not users_nk:
            print("[-] Users key not found.")
            return

        print(f"[+] Found Users key at rel=0x{users_nk.rel_off:08X}")
        child_offsets = self.parse_subkey_list(users_nk.subkey_list_rel, users_nk.subkey_count)
        print(f"[+] Found {len(child_offsets)} subkeys under Users")

        # Build RID->username map from Names subkey (authoritative)
        rid_to_name = self.map_rid_to_username()
        if rid_to_name:
            print("[+] Authoritative username mapping from Names subkey:")
            for rid, name in sorted(rid_to_name.items()):
                print(f"    RID {rid} -> {name}")

        # Collect results for CSV export
        results = []

        for child_abs in child_offsets:
            nk = self.nk_by_abs.get(child_abs)
            if not nk or len(nk.name) != 8:
                continue
            try:
                rid = int(nk.name, 16)
            except ValueError:
                continue

            path = self.get_key_path(nk)
            vks = self.get_vk_list(nk)

            print(f"\n[+] RID key: {nk.name} (RID {rid})")
            print(f"    Path      : {path}")
            print(f"    Timestamp : {filetime_to_str(nk.timestamp)}")
            print(f"    Values    : {len(vks)}")

            if not vks:
                print("    [!] No VK records found for this RID key")
                continue

            f_vk = v_vk = None
            for vk in vks:
                type_name = REG_TYPES.get(vk.value_type, f"UNKNOWN({vk.value_type})")
                print(f"      VK name={vk.name!r} type={type_name} len={vk.data_len} inline={vk.inline}")
                if vk.name == "F":
                    f_vk = vk
                elif vk.name == "V":
                    v_vk = vk

            # Prepare user record (username from Names)
            username = rid_to_name.get(rid, "")
            user_rec = {
                "rid": rid,
                "username": username,          # authoritative
                "account_flags": "",
                "last_logon": "",
                "last_pwd_set": "",
                "account_expires": "",
                "last_failed_logon": "",
                "failed_logon_count": "",
                "logon_count": "",
                "lm_blob": "",
                "nt_blob": "",
                "v_username": "",               # from V (for verification)
                "v_match": False
            }

            f_abs_start = None
            v_abs_start = None
            f_info = None
            v_info = None

            # ----- F value -----
            if f_vk:
                # Absolute offset of F data
                f_abs_start = f_vk.data_rel + FIRST_HBIN_ABS
                hex_dump(f_vk.data, f"F value for {nk.name} (RID {rid})", f_abs_start)
                f_info = auto_parse_f_improved(f_vk.data, rid)
                if f_info:
                    self._print_f_info(f_info)
                    user_rec.update({
                        "account_flags": f_info['flags_readable'],
                        "last_logon": f_info['last_logon'],
                        "last_pwd_set": f_info['last_pwd_set'],
                        "account_expires": f_info['account_expires'],
                        "last_failed_logon": f_info['last_failed_logon'],
                        "failed_logon_count": f_info['failed_logon_count'],
                        "logon_count": f_info['logon_count'],
                    })
                else:
                    print("    Could not parse F value automatically. Use the hex dump above for manual mapping.")

            # ----- V value -----
            if v_vk:
                v_abs_start = v_vk.data_rel + FIRST_HBIN_ABS
                hex_dump(v_vk.data, f"V value for {nk.name} (RID {rid})", v_abs_start)
                v_info = auto_parse_v(v_vk.data, expected_username=username if username else None)
                if v_info and v_info['username']:
                    print(f"        [Auto] Found username at offset 0x{v_info['username_offset']:X}")
                    self._print_v_info(v_info)
                    user_rec.update({
                        "v_username": v_info['username'],
                        "v_match": (v_info['username'] == username),
                        "lm_blob": v_info.get('lm_blob', b'').hex(),
                        "nt_blob": v_info.get('nt_blob', b'').hex(),
                    })
                    if username and v_info['username'] != username:
                        print(f"        [!] Username mismatch: V says '{v_info['username']}', Names says '{username}'")
                else:
                    print("        Could not parse V value automatically. Use the hex dump above for manual mapping.")

            # ----- Print field mapping for Excel -----
            if f_abs_start is not None and v_abs_start is not None:
                self._print_field_mapping(rid, username, nk.abs_off, f_abs_start, f_info, v_abs_start, v_info)

            results.append(user_rec)

        # Write CSV
        if results:
            csv_path = "sam_users.csv"
            with open(csv_path, "w", newline="", encoding="utf-8") as f:
                fieldnames = ["rid", "username", "account_flags", "last_logon", "last_pwd_set",
                              "account_expires", "last_failed_logon", "failed_logon_count",
                              "logon_count", "lm_blob", "nt_blob", "v_username", "v_match"]
                w = csv.DictWriter(f, fieldnames=fieldnames)
                w.writeheader()
                w.writerows(results)
            print(f"\n[+] CSV summary saved to {csv_path}")

    def _print_f_info(self, f_info):
        print(f"        RID in F           : {f_info['rid']}")
        print(f"        Account flags      : 0x{f_info['account_flags']:08X} ({f_info['flags_readable']})")
        print(f"        Last logon         : {f_info['last_logon']}")
        print(f"        Last password set  : {f_info['last_pwd_set']}")
        print(f"        Account expires    : {f_info['account_expires']}")
        print(f"        Last failed logon  : {f_info['last_failed_logon']}")
        print(f"        Failed logon count : {f_info['failed_logon_count']}")
        print(f"        Logon count        : {f_info['logon_count']}")

    def _print_v_info(self, v_info):
        print(f"        Username  : {v_info['username']}")
        lm = v_info.get('lm_blob', b'')
        nt = v_info.get('nt_blob', b'')
        if lm:
            print(f"        LM blob   : {lm.hex()} (raw 16‑byte candidate; may be encrypted)")
        if nt:
            print(f"        NT blob   : {nt.hex()} (raw 16‑byte candidate; may be encrypted)")

    # ------------------------------------------------------------------
    # Search for interesting keys (optional)
    # ------------------------------------------------------------------
    def search_interesting(self):
        print("\n[*] Searching for interesting names directly")
        exact_targets = {"SAM", "Domains", "Account", "Users", "Names",
                         "Administrator", "Guest", "DefaultAccount"}
        found_exact = []
        found_rids = []
        found_probable = []

        for nk in self.nk_by_abs.values():
            if nk.name in exact_targets:
                found_exact.append(nk)
            if len(nk.name) == 8:
                try:
                    rid = int(nk.name, 16)
                    found_rids.append((nk, rid))
                except ValueError:
                    pass
            if nk.name and any(c.isalpha() for c in nk.name):
                if nk.name not in {"ROOT", "RXACT"} and len(nk.name) < 64:
                    found_probable.append(nk)

        if found_exact:
            print("\n[+] Exact target names found")
            for nk in found_exact:
                print(f"    name={nk.name} rel=0x{nk.rel_off:08X} parent=0x{nk.parent_rel:08X} subkeys={nk.subkey_count} values={nk.value_count}")
        if found_rids:
            print("\n[+] RID-style keys found")
            for nk, rid in found_rids:
                print(f"    name={nk.name} RID={rid} rel=0x{nk.rel_off:08X} parent=0x{nk.parent_rel:08X} values={nk.value_count}")
        if found_probable:
            print("\n[+] Likely user/group names")
            seen = set()
            for nk in found_probable:
                if nk.name not in seen:
                    seen.add(nk.name)
                    print(f"    {nk.name}")

    # ------------------------------------------------------------------
    # Main entry point
    # ------------------------------------------------------------------
    def run(self):
        self.parse_header()
        self.parse_hbins()
        self.scan_nks()
        self.search_interesting()
        self.extract_users()


# ----------------------------------------------------------------------
# Main
# ----------------------------------------------------------------------
def main():
    if len(sys.argv) != 2:
        print("Usage: py sam_parser.py <SAM_hive_file>")
        sys.exit(1)

    parser = SAMParser(sys.argv[1])
    parser.run()


if __name__ == "__main__":
    main()