#Modified Bluetooth Transmission Protocol

from bisect import bisect_right

def solve(k, n, fs, ms):
    # The transmission frequencies should be sorted for binary search
    fs.sort()
    results = []
    for m in ms:
        # Use binary search to find the count of frequencies <= m
        count = bisect_right(fs, m)
        results.append(count)
    return results

#do not edit or add to the code below this line
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    k = int(data[0])
    n = int(data[1])
    
    fs = []
    for i in range(k):
        fs.append(int(data[2 + i]))
    
    ms = []
    for i in range(n):
        ms.append(int(data[2 + k + i]))
    
    ans = solve(k, n, fs, ms)
    
    print("\n".join(list(map(str, ans))))

if __name__ == "__main__":
    main()