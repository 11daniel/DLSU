import hashlib
import os
import pandas as pd
import magic
magic_lib = magic.Magic(mime=True)
from PIL import Image
from PIL.ExifTags import TAGS
import re  

def compute_sha256(file_path):
    sha256 = hashlib.sha256()
    try:
        with open(file_path, "rb") as f:
            while chunk := f.read(8192):
                sha256.update(chunk)
        return sha256.hexdigest()
    except FileNotFoundError:
        return "File not found"

def get_magic_number(file_path):
    try:
        with open(file_path, "rb") as f:
            magic_number = f.read(8)
        hex_magic = magic_number.hex()
        ascii_magic = magic_number.decode(errors="ignore")
        return hex_magic, "0x0", ascii_magic
    except FileNotFoundError:
        return "File not found", None, None

def get_metadata(file_path):
    try:
        with Image.open(file_path) as img:
            metadata = {TAGS.get(tag): value for tag, value in img._getexif().items()} if img._getexif() else {}
            return str(metadata)
    except Exception:
        return "No metadata found or not an image."

def clean_text(text):
    if isinstance(text, str):
        return re.sub(r'[\x00-\x1F\x7F-\x9F]', '', text)
    return text  

directory = r"C:\Users\nicos\OneDrive\Documents\DLSU\Term 8\NSSECU3\FileAnalysis\File"  

files = [os.path.join(directory, f) for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

results = []

for file in files:
    print(f"Processing: {file}")
    
    sha256_hash = compute_sha256(file)
    magic_hex, offset, magic_ascii = get_magic_number(file)
    metadata = get_metadata(file)
    
    results.append({
        "File Name": os.path.basename(file),
        "SHA-256 Hash": sha256_hash,
        "Magic Number (Hex)": magic_hex,
        "Offset": offset,
        "Magic ASCII": magic_ascii,
        "Metadata": metadata
    })

df = pd.DataFrame(results)
df = df.applymap(clean_text)  

output_file = "file_analysis_results.xlsx"
df.to_excel(output_file, index=False)

print(f"\n Analysis complete! Results saved to {output_file}")