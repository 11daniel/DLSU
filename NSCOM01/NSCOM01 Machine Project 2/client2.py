import sys
import time
import tkinter as tk
from tkinter import ttk
from sip_utils import SIPClient
from rtp_utils import RTPReceiver
from audio_utils import AudioPlayer
import threading

class VoIPReceiverGUI:
    def __init__(self, root, local_ip, local_port, remote_ip, remote_port):
        self.root = root
        self.local_ip = local_ip
        self.local_port = local_port
        self.remote_ip = remote_ip
        self.remote_port = remote_port
        self.running = False
        
        self.setup_gui()
        
    def setup_gui(self):
        self.root.title("VoIP Receiver")
        self.root.geometry("300x150")
        
        # Status label
        self.status_var = tk.StringVar(value="Ready")
        ttk.Label(self.root, textvariable=self.status_var).pack(pady=10)
        
        # Control buttons
        btn_frame = ttk.Frame(self.root)
        btn_frame.pack(pady=10)
        
        self.play_btn = ttk.Button(btn_frame, text="Listen", command=self.start_receiving)
        self.play_btn.pack(side=tk.LEFT, padx=5)
        
        self.stop_btn = ttk.Button(btn_frame, text="Stop", command=self.stop_receiving, state=tk.DISABLED)
        self.stop_btn.pack(side=tk.LEFT, padx=5)
        
        # Close handler
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
    
    def start_receiving(self):
        self.status_var.set("Waiting for call...")
        self.play_btn.config(state=tk.DISABLED)
        self.stop_btn.config(state=tk.NORMAL)
        self.running = True
        
        voip_thread = threading.Thread(target=self.voip_session, daemon=True)
        voip_thread.start()
    
    def voip_session(self):
        try:
            print(f"\nStarting Client 2 (Receiver) on {self.local_ip}:{self.local_port}")
            print(f"Expecting Client 1 at {self.remote_ip}:{self.remote_port}\n")

            # Initialize SIP client
            sip_client = SIPClient(self.local_ip, self.local_port + 100, 
                                 self.remote_ip, self.remote_port + 100)
            
            # Wait for INVITE
            print("[SIP] Waiting for INVITE...")
            while self.running:
                invite = sip_client.receive_message()
                if invite:
                    print(f"[SIP] Received message:\n{invite.decode()[:500]}...")
                    break
                time.sleep(0.1)
            
            if not self.running:
                return

            if b"INVITE" not in invite:
                print("[SIP] Received message is not an INVITE")
                self.status_var.set("Invalid call received")
                return

            # Parse the INVITE
            try:
                invite_lines = invite.decode().split('\r\n')
                via_header = next(line for line in invite_lines if line.lower().startswith('via:'))
                from_header = next(line for line in invite_lines if line.lower().startswith('from:'))
                call_id = next(line for line in invite_lines if line.lower().startswith('call-id:'))
                cseq = next(line for line in invite_lines if line.lower().startswith('cseq:'))
            except StopIteration:
                print("[SIP] Malformed INVITE - missing required headers")
                self.status_var.set("Malformed call received")
                return

            # Send 200 OK with SDP
            rtp_port = self.local_port
            sdp_response = (
                "v=0\r\n"
                f"o=- {sip_client.call_id} 0 IN IP4 {self.local_ip}\r\n"
                "s=VoIP Call\r\n"
                f"c=IN IP4 {self.local_ip}\r\n"
                "t=0 0\r\n"
                f"m=audio {rtp_port} RTP/AVP 0\r\n"
                "a=rtpmap:0 PCMU/8000\r\n"
            )
            
            ok_response = (
                "SIP/2.0 200 OK\r\n"
                f"{via_header}\r\n"
                f"{from_header};tag={sip_client.tag}\r\n"
                f"To: <sip:user@{self.local_ip}>;tag={sip_client.tag}\r\n"
                f"{call_id}\r\n"
                f"{cseq}\r\n"
                "Contact: <sip:user@{}:{}>\r\n".format(self.local_ip, self.local_port + 100) +
                "Content-Type: application/sdp\r\n"
                "Content-Length: {}\r\n\r\n".format(len(sdp_response)) +
                sdp_response
            )
            
            print("[SIP] Sending 200 OK response:")
            sip_client.send_message(ok_response)
            
            # Wait for ACK
            print("[SIP] Waiting for ACK...")
            while self.running:
                ack = sip_client.receive_message()
                if ack:
                    print(f"[SIP] Received ACK:\n{ack.decode()[:500]}...")
                    break
                time.sleep(0.1)
            
            if not self.running:
                return

            # Initialize audio player and RTP receiver
            audio_player = AudioPlayer()
            print(f"[RTP] Initializing RTP receiver on port {rtp_port}")
            self.status_var.set("Receiving audio...")
            
            def rtp_callback(payload, timestamp, seq_num, ssrc):
                if payload and self.running:
                    try:
                        audio_player.play_audio(payload)
                    except Exception as e:
                        print(f"[AUDIO] Playback error: {e}")

            rtp_receiver = RTPReceiver(self.local_ip, rtp_port)
            rtp_receiver.receive_packets(rtp_callback)
            
            # Wait for BYE
            print("[SIP] Waiting for BYE...")
            while self.running:
                bye = sip_client.receive_message()
                if bye:
                    print(f"[SIP] Received BYE:\n{bye.decode()[:500]}...")
                    # Send 200 OK to BYE
                    ok_response = (
                        "SIP/2.0 200 OK\r\n"
                        f"{via_header}\r\n"
                        f"{from_header};tag={sip_client.tag}\r\n"
                        f"To: <sip:user@{self.local_ip}>;tag={sip_client.tag}\r\n"
                        f"{call_id}\r\n"
                        f"{cseq}\r\n"
                        "Content-Length: 0\r\n\r\n"
                    )
                    sip_client.send_message(ok_response)
                    print("[SIP] Sent 200 OK to BYE")
                    break
                time.sleep(0.1)
            
            if self.running:
                self.status_var.set("Call ended by remote")
            
        except Exception as e:
            print(f"\n[ERROR] Fatal error: {e}")
            self.status_var.set(f"Error: {str(e)}")
        finally:
            self.running = False
            self.root.after(100, lambda: self.stop_btn.config(state=tk.DISABLED))
            self.root.after(100, lambda: self.play_btn.config(state=tk.NORMAL))
            try:
                audio_player.close()
            except:
                pass
    
    def stop_receiving(self):
        self.status_var.set("Stopping...")
        self.running = False
    
    def on_close(self):
        self.stop_receiving()
        self.root.destroy()

def main():
    if len(sys.argv) < 5:
        print("Usage: python client2.py <local_ip> <local_port> <remote_ip> <remote_port>")
        print("Example for local testing:")
        print("python client2.py 127.0.0.1 6002 127.0.0.1 6000")
        return
    
    root = tk.Tk()
    app = VoIPReceiverGUI(root, 
                         sys.argv[1], int(sys.argv[2]),
                         sys.argv[3], int(sys.argv[4]))
    root.mainloop()

if __name__ == "__main__":
    main()