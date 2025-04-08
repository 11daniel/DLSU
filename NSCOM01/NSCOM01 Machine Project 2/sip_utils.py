import socket
import random
import time

class SIPClient:
    def __init__(self, local_ip, local_port, remote_ip, remote_port):
        self.local_ip = local_ip
        self.local_port = local_port
        self.remote_ip = remote_ip
        self.remote_port = remote_port
        self.call_id = str(random.randint(100000, 999999))
        self.cseq = 1
        self.tag = str(random.randint(1000, 9999))
        self.sip_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sip_socket.bind((local_ip, local_port))
        self.sip_socket.settimeout(5.0)
        
    def generate_invite(self, rtp_port, codec="PCMU"):
        """Generate SIP INVITE message with SDP"""
        self.cseq += 1
        sdp = (
            "v=0\r\n"
            f"o=- {self.call_id} 0 IN IP4 {self.local_ip}\r\n"
            "s=VoIP Call\r\n"
            "c=IN IP4 {}\r\n".format(self.local_ip) +
            "t=0 0\r\n"
            "m=audio {} RTP/AVP 0\r\n".format(rtp_port) +
            "a=rtpmap:0 PCMU/8000\r\n"
        )
        
        invite_msg = (
            "INVITE sip:user@{}\r\n".format(self.remote_ip) +
            "Via: SIP/2.0/UDP {}:{};branch=z9hG4bK{}\r\n".format(
                self.local_ip, self.local_port, random.randint(1000, 9999)) +
            "Max-Forwards: 70\r\n"
            f"From: <sip:user1@{self.local_ip}>;tag={self.tag}\r\n"
            f"To: <sip:user2@{self.remote_ip}>\r\n"
            f"Call-ID: {self.call_id}@{self.local_ip}\r\n"
            f"CSeq: {self.cseq} INVITE\r\n"
            "Contact: <sip:user1@{}:{}>\r\n".format(self.local_ip, self.local_port) +
            "Content-Type: application/sdp\r\n"
            "Content-Length: {}\r\n\r\n".format(len(sdp)) +
            sdp
        )
        return invite_msg
    
    def generate_ack(self):
        """Generate SIP ACK message"""
        self.cseq += 1
        ack_msg = (
            "ACK sip:user@{}\r\n".format(self.remote_ip) +
            "Via: SIP/2.0/UDP {}:{};branch=z9hG4bK{}\r\n".format(
                self.local_ip, self.local_port, random.randint(1000, 9999)) +
            "Max-Forwards: 70\r\n"
            f"From: <sip:user1@{self.local_ip}>;tag={self.tag}\r\n"
            f"To: <sip:user2@{self.remote_ip}>;tag={self.remote_tag}\r\n"
            f"Call-ID: {self.call_id}@{self.local_ip}\r\n"
            f"CSeq: {self.cseq} ACK\r\n"
            "Content-Length: 0\r\n\r\n"
        )
        return ack_msg
    
    def generate_bye(self):
        """Generate SIP BYE message"""
        self.cseq += 1
        bye_msg = (
            "BYE sip:user@{}\r\n".format(self.remote_ip) +
            "Via: SIP/2.0/UDP {}:{};branch=z9hG4bK{}\r\n".format(
                self.local_ip, self.local_port, random.randint(1000, 9999)) +
            "Max-Forwards: 70\r\n"
            f"From: <sip:user1@{self.local_ip}>;tag={self.tag}\r\n"
            f"To: <sip:user2@{self.remote_ip}>;tag={self.remote_tag}\r\n"
            f"Call-ID: {self.call_id}@{self.local_ip}\r\n"
            f"CSeq: {self.cseq} BYE\r\n"
            "Content-Length: 0\r\n\r\n"
        )
        return bye_msg
    
    def parse_response(self, data):
        """Parse SIP response and extract important information"""
        lines = data.decode().split('\r\n')
        status_line = lines[0]
        status_code = int(status_line.split(' ')[1])
        
        headers = {}
        for line in lines[1:]:
            if ': ' in line:
                key, value = line.split(': ', 1)
                headers[key.lower()] = value
        
        if 'to' in headers and 'tag=' in headers['to']:
            self.remote_tag = headers['to'].split('tag=')[1].split(';')[0]
        
        sdp = {}
        if status_code == 200 and '\r\n\r\n' in data.decode():
            sdp_part = data.decode().split('\r\n\r\n')[1]
            for line in sdp_part.split('\r\n'):
                if line.startswith('m='):
                    sdp['media_port'] = int(line.split(' ')[1])
                elif line.startswith('c='):
                    sdp['ip'] = line.split(' ')[2]
        
        return status_code, headers, sdp
    
    def send_message(self, message, dest_ip=None, dest_port=None):
        """Send SIP message to remote party"""
        if dest_ip is None:
            dest_ip = self.remote_ip
        if dest_port is None:
            dest_port = self.remote_port
        self.sip_socket.sendto(message.encode(), (dest_ip, dest_port))
    
    def receive_message(self):
        """Receive SIP message with timeout"""
        try:
            data, addr = self.sip_socket.recvfrom(65535)
            return data
        except socket.timeout:
            return None