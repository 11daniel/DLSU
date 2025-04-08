import socket
import struct
import time
import random

class RTPPacket:
    def __init__(self):
        self.version = 2
        self.padding = 0
        self.extension = 0
        self.csrc_count = 0
        self.marker = 0
        self.payload_type = 0  # PCMU
        self.sequence_number = random.randint(0, 65535)
        self.timestamp = 0
        self.ssrc = random.randint(0, 0xFFFFFFFF)
        self.payload = b''
    
    def pack(self):
        """Pack RTP packet into bytes"""
        header = (
            (self.version << 6) |
            (self.padding << 5) |
            (self.extension << 4) |
            self.csrc_count
        )
        
        header2 = (
            (self.marker << 7) |
            self.payload_type
        )
        
        packet = struct.pack(
            '!BBHII',
            header,
            header2,
            self.sequence_number,
            self.timestamp,
            self.ssrc
        )
        
        return packet + self.payload

class RTPSender:
    def __init__(self, local_ip, local_port, remote_ip, remote_port):
        self.local_ip = local_ip
        self.local_port = local_port
        self.remote_ip = remote_ip
        self.remote_port = remote_port
        self.rtp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rtp_socket.bind((local_ip, local_port))
        self.rtp_packet = RTPPacket()
        self.rtp_packet.ssrc = random.randint(0, 0xFFFFFFFF)
        self.sequence_number = random.randint(0, 65535)
        self.timestamp = 0
        self.packet_count = 0
        self.octet_count = 0
    
    def send_packet(self, payload, marker=0):
        """Send RTP packet with payload"""
        self.rtp_packet.sequence_number = self.sequence_number
        self.rtp_packet.timestamp = self.timestamp
        self.rtp_packet.marker = marker
        self.rtp_packet.payload = payload
        
        packet = self.rtp_packet.pack()
        self.rtp_socket.sendto(packet, (self.remote_ip, self.remote_port))
        
        self.sequence_number += 1
        self.timestamp += len(payload)  # Assuming 8kHz sample rate
        self.packet_count += 1
        self.octet_count += len(payload)
        
        # Send RTCP SR every 20 packets
        if self.packet_count % 20 == 0:
            self.send_rtcp_report()
    
    def send_rtcp_report(self):
        """Send simple RTCP Sender Report"""
        version = 2
        padding = 0
        rc = 0  # reception report count
        packet_type = 200  # SR
        length = 6  # in 32-bit words - 1
        ssrc = self.rtp_packet.ssrc
        
        # Get NTP timestamp (simplified)
        ntp_time = time.time()
        ntp_sec = int(ntp_time)
        ntp_frac = int((ntp_time - ntp_sec) * 4294967296)  # 2^32
        
        rtcp_packet = struct.pack(
            '!BBHIIIIII',
            (version << 6) | (padding << 5) | rc,
            packet_type,
            length,
            ssrc,
            ntp_sec + 2208988800,  # Convert to NTP epoch (1900-1970)
            ntp_frac,
            self.timestamp,
            self.packet_count,
            self.octet_count
        )
        
        self.rtp_socket.sendto(rtcp_packet, (self.remote_ip, self.remote_port + 1))

class RTPReceiver:
    def __init__(self, local_ip, local_port):
        self.local_ip = local_ip
        self.local_port = local_port
        self.rtp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rtp_socket.bind((local_ip, local_port))
        self.rtp_socket.settimeout(5.0)
        self.rtcp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rtcp_socket.bind((local_ip, local_port + 1))
        self.rtcp_socket.settimeout(5.0)
        self.running = False
    
    def receive_packets(self, callback):
        """Receive RTP packets and pass to callback"""
        self.running = True
        while self.running:
            try:
                data, addr = self.rtp_socket.recvfrom(65535)
                if len(data) >= 12:  # Minimum RTP header size
                    # Parse RTP header
                    header = struct.unpack('!BBHII', data[:12])
                    version = (header[0] >> 6) & 0x03
                    payload_type = header[1] & 0x7F
                    sequence_number = header[2]
                    timestamp = header[3]
                    ssrc = header[4]
                    payload = data[12:]
                    
                    callback(payload, timestamp, sequence_number, ssrc)
            except socket.timeout:
                continue
    
    def stop(self):
        """Stop receiving packets"""
        self.running = False