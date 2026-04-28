import pandas as pd
import requests
import time
from itertools import cycle
from queue import Queue
from threading import Thread, Lock

API_KEYS = [
    "2ce12a86f2855239f68b0defe0321552fc15a33aa59bf8f1740dd2437ab7f245",
    "233d4fda88ebf31c8612cb8bc29abcbbe1453c71b5ddba68582ec3ecdd65c669",
    "d7193bb495256568dbb115bfec8f0fb90b585de23bae91ea97cf7390b6ca9975",
    "fa25a44809e8db8b5c16dddc864b57f6c864399d9d6a9b75323b25503355b17f",
    "7aac4d0333d9f9f2d86bd650183f85ed1ceaa1f679d8a8831575485d7619fc9f",
    "cfbf73396a35bc55bb6a45f4038d1e7c0404907a2bececdf12e1d845d190fddb",
    "6b1757c26190ef58e0afce669a0d3bcf0f9056e031d65dd4bd2f05a2a1b2a7d9",
    "b54795a48951c9867088509bf3d788dbea0c47e6e712ba250f56de20e4ffc710"
]

API_CYCLE = cycle(API_KEYS)
API_LOCK = Lock()
REQUESTS_PER_KEY_PER_MIN = 4
SLEEP_TIME = 16
OUTPUT_FILE = "C:/Users/nicos/OneDrive/Documents/DLSU/Term 8/NSSECU3/IOCFileHash/virustotal_results.csv"

def read_hashes_from_excel(file_path):
    df = pd.read_excel(file_path)
    if df.empty:
        print("Error: The Excel file is empty.")
        return []
    return df.iloc[:, 0].dropna().astype(str).tolist()

def query_virustotal(file_hash):
    while True:
        with API_LOCK:
            api_key = next(API_CYCLE)
        
        url = f"https://www.virustotal.com/api/v3/files/{file_hash}"
        headers = {"x-apikey": api_key}
        response = requests.get(url, headers=headers)
        
        if response.status_code == 200:
            print(f" Success: {file_hash} (API Key: {api_key})")
            return response.json()
        elif response.status_code == 404:
            return {"error": "Not found"}
        elif response.status_code == 429:
            print(f"Rate limit hit for key: {api_key}. Sleeping for {SLEEP_TIME}s...")
            time.sleep(SLEEP_TIME)
            continue
        else:
            return {"error": f"API error {response.status_code}"}

def extract_info(file_hash, virus_total_data):
    if "error" in virus_total_data:
        return {"Hash": file_hash, "Detection Count": "Not Found", "Name1": "N/A", "Name2": "N/A", "Name3": "N/A", "Verdict": "Unknown"}
    
    data = virus_total_data.get("data", {}).get("attributes", {})
    analysis_stats = data.get("last_analysis_stats", {})
    
    detected_names = {"Name1": "None", "Name2": "None", "Name3": "None"}
    malicious_results = data.get("last_analysis_results", {})
    
    for engine, result in malicious_results.items():
        if result.get("result") in detected_names:
            detected_names[result.get("result")] = result.get("result")
    
    return {
        "Hash": file_hash,
        "Detection Count": analysis_stats.get("malicious", 0),
        "Hash-MD5": data.get("md5", "N/A"),
        "Hash-SHA1": data.get("sha1", "N/A"),
        "Hash-SHA256": data.get("sha256", "N/A"),
        "File Type": data.get("type_description", "N/A"),
        "Magic": data.get("magic", "N/A"),
        "Creation Time": data.get("creation_time", "N/A"),
        "Signature Date": data.get("signature_date", "N/A"),
        "First Seen In The Wild": data.get("first_seen_itw_date", "N/A"),
        "First Submission": data.get("first_submission_date", "N/A"),
        "Last Submission": data.get("last_submission_date", "N/A"),
        "Last Analysis": data.get("last_analysis_date", "N/A"),
        "Name1": detected_names["Name1"],
        "Name2": detected_names["Name2"],
        "Name3": detected_names["Name3"],
        "Verdict": "Malicious" if analysis_stats.get("malicious", 0) > 10 else "Benign"
    }

def worker(queue):
    while not queue.empty():
        file_hash = queue.get()
        print(f"Checking hash: {file_hash}...")
        vt_data = query_virustotal(file_hash)
        result = extract_info(file_hash, vt_data)
        results.append(result)
        queue.task_done()
        time.sleep(SLEEP_TIME)

def main():
    file_path = "C:/Users/nicos/OneDrive/Documents/DLSU/Term 8/NSSECU3/IOCFileHash/hashes2.xlsx"
    hashes = read_hashes_from_excel(file_path)
    if not hashes:
        print("No hashes found in the file.")
        return
    
    queue = Queue()
    for file_hash in hashes:
        queue.put(file_hash)
    
    global results
    results = []
    
    num_threads = len(API_KEYS)
    threads = []
    for _ in range(num_threads):
        t = Thread(target=worker, args=(queue,))
        t.start()
        threads.append(t)
    
    for t in threads:
        t.join()
    
    results_df = pd.DataFrame(results)
    results_df.to_csv(OUTPUT_FILE, index=False)
    print(f"Results saved to {OUTPUT_FILE}")

if __name__ == "__main__":
    main()
