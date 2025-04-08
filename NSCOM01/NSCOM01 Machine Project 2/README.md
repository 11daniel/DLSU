# VoIP Application with SIP and RTP

A simple VoIP implementation using SIP for signaling and RTP for audio transmission. The application consists of two clients - a sender (client1.py) that streams audio from a WAV file, and a receiver (client2.py) that plays the received audio.

## Prerequisites
- Python 3.x
- tkinter (usually included with Python)
- pyaudio (`pip install pyaudio`)

## Instructions for Running

### 1. Open two terminal windows
You'll need one for the sender and one for the receiver.

### 2. Run the sender (Client 1)
```
python client1.py <local_ip> <local_port> <remote_ip> <remote_port>
```
Example for local testing:
```
python client1.py 127.0.0.1 6000 127.0.0.1 6002
```

### 3. Run the receiver (Client 2)
```
python client2.py <local_ip> <local_port> <remote_ip> <remote_port>
```
Example matching the sender:
```
python client2.py 127.0.0.1 6002 127.0.0.1 6000
```
### 4. Using the GUI Applications

#### Sender (Client 1):
1. Click "Browse" to select a WAV audio file
2. Click "Start Call" to initiate the VoIP session
3. Click "End Call" to terminate the session

#### Receiver (Client 2):
1. Click "Listen" to wait for incoming calls
2. Click "Stop" to stop receiving

## Implementation Details

### Key Features
✅ SIP Protocol Implementation:
- INVITE, 200 OK, ACK, and BYE messages
- SDP negotiation for RTP parameters

✅ RTP Audio Streaming:
- PCMU codec support
- Packet sequencing and timing
- Basic RTCP sender reports

✅ GUI Interface:
- Simple controls for call management
- Status feedback

✅ Error Handling:
- SIP message parsing and validation
- Timeout handling
- Audio file validation

### Port Usage
- SIP signaling uses the specified port + 100 (e.g., 6000 becomes 6100)
- RTP uses the specified port (e.g., 6000)
- RTCP uses RTP port + 1 (e.g., 6001)

## Testing and Troubleshooting

### Test Cases
| Test Case | Expected Result |
|-----------|-----------------|
| Start call with valid WAV file | Audio should play on receiver |
| Try starting call without selecting file | Error message in status |
| End call during transmission | Audio should stop immediately |
| Network interruption | Call should timeout after 10 seconds |

### Useful Commands
Check if ports are available:
netstat -an | find "6000"


Test audio playback (verify pyaudio works):
```python
import pyaudio
p = pyaudio.PyAudio()
p.terminate()
```
Verify Python version:
python --version

### Known Limitations

Only supports WAV files with specific format (16-bit PCM, 8000Hz)

No encryption of audio streams

Basic error recovery only

---
This README provides clear instructions for running the application, explains its features, and includes troubleshooting tips. You may want to adjust the port numbers or add specific notes about your testing environment as needed.
