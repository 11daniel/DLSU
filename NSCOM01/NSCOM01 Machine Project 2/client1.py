import sys
import time
import tkinter as tk
from tkinter import ttk, filedialog
from sip_utils import SIPClient
from rtp_utils import RTPSender
from audio_utils import AudioFileHandler
import threading

class VoIPSenderGUI:
    def __init__(self, root, local_ip, local_port, remote_ip, remote_port):
        self.root = root
        self.local_ip = local_ip
        self.local_port = local_port
        self.remote_ip = remote_ip
        self.remote_port = remote_port
        self.audio_file = ""
        self.running = False
        
        self.setup_gui()
        
    def setup_gui(self):
        self.root.title("VoIP Sender")
        self.root.geometry("400x200")
        
        # File selection
        file_frame = ttk.Frame(self.root)
        file_frame.pack(pady=10)
        
        ttk.Label(file_frame, text="Audio File:").pack(side=tk.LEFT)
        self.file_entry = ttk.Entry(file_frame, width=30)
        self.file_entry.pack(side=tk.LEFT, padx=5)
        ttk.Button(file_frame, text="Browse", command=self.browse_file).pack(side=tk.LEFT)
        
        # Status label
        self.status_var = tk.StringVar(value="Select an audio file")
        ttk.Label(self.root, textvariable=self.status_var).pack(pady=10)
        
        # Control buttons
        btn_frame = ttk.Frame(self.root)
        btn_frame.pack(pady=10)
        
        self.call_btn = ttk.Button(btn_frame, text="Start Call", command=self.start_call, state=tk.DISABLED)
        self.call_btn.pack(side=tk.LEFT, padx=5)
        
        self.stop_btn = ttk.Button(btn_frame, text="End Call", command=self.end_call, state=tk.DISABLED)
        self.stop_btn.pack(side=tk.LEFT, padx=5)
        
        # Close handler
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
    
    def browse_file(self):
        filename = filedialog.askopenfilename(filetypes=[("WAV files", "*.wav")])
        if filename:
            self.audio_file = filename
            self.file_entry.delete(0, tk.END)
            self.file_entry.insert(0, filename)
            self.call_btn.config(state=tk.NORMAL)
            self.status_var.set("Ready to call")
    
    def start_call(self):
        if not self.audio_file:
            self.status_var.set("No audio file selected")
            return
            
        self.status_var.set("Starting call...")
        self.call_btn.config(state=tk.DISABLED)
        self.stop_btn.config(state=tk.NORMAL)
        self.running = True
        
        call_thread = threading.Thread(target=self.voip_call, daemon=True)
        call_thread.start()
    
    def voip_call(self):
        try:
            print(f"\nStarting Client 1 (Sender) on {self.local_ip}:{self.local_port}")
            print(f"Targeting Client 2 at {self.remote_ip}:{self.remote_port}")
            print(f"Audio file: {self.audio_file}\n")

            # Initialize SIP client
            sip_client = SIPClient(self.local_ip, self.local_port + 100, 
                                 self.remote_ip, self.remote_port + 100)
            
            # Choose RTP port
            rtp_port = self.local_port
            
            # Send INVITE
            invite_msg = sip_client.generate_invite(rtp_port)
            print(f"[SIP] Sending INVITE to {self.remote_ip}:{self.remote_port + 100}")
            sip_client.send_message(invite_msg)
            
            # Wait for 200 OK
            print("[SIP] Waiting for 200 OK response...")
            start_time = time.time()
            while time.time() - start_time < 10 and self.running:
                response = sip_client.receive_message()
                if response:
                    print(f"[SIP] Received response:\n{response.decode()[:500]}...")
                    status_code, headers, sdp = sip_client.parse_response(response)
                    if status_code == 200:
                        print("[SIP] Received 200 OK")
                        remote_rtp_port = sdp['media_port']
                        break
                    else:
                        print(f"[SIP] Error response: {status_code}")
                        self.status_var.set(f"Call failed: {status_code}")
                        return
                time.sleep(0.1)
            else:
                if self.running:
                    print("[SIP] Timeout waiting for 200 OK")
                    self.status_var.set("Call timed out")
                return
            
            # Send ACK
            ack_msg = sip_client.generate_ack()
            print("[SIP] Sending ACK")
            sip_client.send_message(ack_msg)
            
            # Initialize RTP sender
            print(f"[RTP] Initializing RTP sender on port {rtp_port}")
            rtp_sender = RTPSender(self.local_ip, rtp_port, self.remote_ip, remote_rtp_port)
            
            # Load audio file
            print(f"[AUDIO] Loading audio file: {self.audio_file}")
            try:
                audio_handler = AudioFileHandler(self.audio_file)
                print(f"[AUDIO] Audio duration: {audio_handler.get_duration():.2f} seconds")
                
                # Send audio in RTP packets
                print("[RTP] Starting RTP stream...")
                self.status_var.set("Call in progress...")
                
                for i, chunk in enumerate(audio_handler.get_audio_chunks()):
                    if not self.running:
                        break
                    rtp_sender.send_packet(chunk, marker=0)
                    if i % 50 == 0:
                        print(f"[RTP] Sent packet {i}")
                    time.sleep(0.020)
                
                if self.running:
                    # Send final packet with marker bit
                    rtp_sender.send_packet(b'', marker=1)
                    print("[RTP] Stream complete")
            except Exception as e:
                print(f"[AUDIO] Error: {e}")
                self.status_var.set(f"Audio error: {str(e)}")
                return
            
            # Send BYE to terminate session
            if self.running:
                bye_msg = sip_client.generate_bye()
                print("[SIP] Sending BYE")
                sip_client.send_message(bye_msg)
                
                # Wait for 200 OK to BYE
                print("[SIP] Waiting for 200 OK to BYE...")
                response = sip_client.receive_message()
                if response:
                    status_code, _, _ = sip_client.parse_response(response)
                    if status_code == 200:
                        print("[SIP] Call terminated successfully")
            
            if self.running:
                self.status_var.set("Call completed")
            
        except Exception as e:
            print(f"\n[ERROR] Fatal error: {e}")
            self.status_var.set(f"Error: {str(e)}")
        finally:
            self.running = False
            self.root.after(100, lambda: self.stop_btn.config(state=tk.DISABLED))
            self.root.after(100, lambda: self.call_btn.config(state=tk.NORMAL))
    
    def end_call(self):
        self.status_var.set("Ending call...")
        self.running = False
        
        # Force close sockets to unblock threads
        if hasattr(self, 'rtp_sender') and self.rtp_socket:
            self.rtp_socket.close()  # Force close socket to unblock
    
    def on_close(self):
        self.end_call()
        self.root.destroy()

def main():
    if len(sys.argv) < 5:
        print("Usage: python client1.py <local_ip> <local_port> <remote_ip> <remote_port>")
        print("Example for local testing:")
        print("python client1.py 127.0.0.1 6000 127.0.0.1 6002")
        return
    
    root = tk.Tk()
    app = VoIPSenderGUI(root, 
                       sys.argv[1], int(sys.argv[2]),
                       sys.argv[3], int(sys.argv[4]))
    root.mainloop()

if __name__ == "__main__":
    main()