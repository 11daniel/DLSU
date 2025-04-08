import wave
import pyaudio
import time

class AudioPlayer:
    def __init__(self):
        self.p = pyaudio.PyAudio()
        self.stream = None
    
    def play_audio(self, audio_data, sample_rate=8000, channels=1):
        """Play audio data using PyAudio"""
        if self.stream is None:
            self.stream = self.p.open(
                format=self.p.get_format_from_width(2),  # 16-bit PCM
                channels=channels,
                rate=sample_rate,
                output=True
            )
        
        self.stream.write(audio_data)
    
    def close(self):
        """Close audio resources"""
        if self.stream is not None:
            self.stream.stop_stream()
            self.stream.close()
        self.p.terminate()

class AudioFileHandler:
    def __init__(self, filename):
        self.filename = filename
        self.audio_data = b''
        self.sample_rate = 8000
        self.channels = 1
        self.sample_width = 2  # 16-bit PCM
        
        if filename.endswith('.wav'):
            self._read_wav_file()
    
    def _read_wav_file(self):
        """Read WAV file and store audio data"""
        with wave.open(self.filename, 'rb') as wf:
            self.channels = wf.getnchannels()
            self.sample_width = wf.getsampwidth()
            self.sample_rate = wf.getframerate()
            self.audio_data = wf.readframes(wf.getnframes())
    
    def get_audio_chunks(self, chunk_size=160):
        """Generator that yields audio chunks"""
        for i in range(0, len(self.audio_data), chunk_size):
            yield self.audio_data[i:i + chunk_size]
    
    def get_duration(self):
        """Get audio duration in seconds"""
        return len(self.audio_data) / (self.sample_rate * self.sample_width * self.channels)