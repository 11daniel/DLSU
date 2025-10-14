# PowerShell script for Windows 7 SMB Enumeration Lab Setup
# Must be run as Administrator

# === Enable File and Printer Sharing (via netsh) ===
cmd /c 'netsh advfirewall firewall set rule group="File and Printer Sharing" new enable=Yes'

# === Enable and start Remote Registry Service ===
cmd /c 'sc config remoteregistry start= auto'
cmd /c 'net start remoteregistry'

# === Create vulnerable share folder ===
$sharePath = "C:\HackMe"
if (!(Test-Path $sharePath)) {
    New-Item -ItemType Directory -Path $sharePath | Out-Null
}
cmd /c "icacls $sharePath /grant Everyone:F"
cmd /c "net share hackme=`"$sharePath`" /grant:everyone,full"

# === Share Public Folder (already exists) ===
cmd /c 'net share public="C:\Users\Public" /grant:everyone,full'

# === Create Weak User Accounts ===
cmd /c 'net user student student123 /add'
cmd /c 'net localgroup administrators student /add'
cmd /c 'net user DLSU_User "" /add'

# === Disable Windows Firewall (All Profiles) ===
cmd /c 'netsh advfirewall set allprofiles state off'

# === Add Registry Settings to Enable Null Sessions ===
# RestrictAnonymous = 0
reg add "HKLM\SYSTEM\CurrentControlSet\Control\Lsa" /v RestrictAnonymous /t REG_DWORD /d 0 /f

# RestrictAnonymousSAM = 0
reg add "HKLM\SYSTEM\CurrentControlSet\Control\Lsa" /v RestrictAnonymousSAM /t REG_DWORD /d 0 /f

# NullSessionShares = "hackme"
reg add "HKLM\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters" /v NullSessionShares /t REG_MULTI_SZ /d "hackme" /f

Write-Host "=== SMB Lab Setup Complete. Reboot your machine to apply all changes. ==="
