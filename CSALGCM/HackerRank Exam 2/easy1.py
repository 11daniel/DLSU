#The Unending Towers of Algorismus

MOD = int(1e9 + 7)

# Read input values
k, q = list(map(int, input().split()))

# Read all the queries
queries = [int(input()) for _ in range(q)]

# Determine the maximum N we need to compute
max_n = max(queries)

# Initialize the DP table
dp = [0] * (max_n + 1)
dp[1] = k

# Precompute U(N) for all 1 <= N <= max_n
for n in range(2, max_n + 1):
    if n % 2 == 0:
        # N is even
        dp[n] = sum(dp[1:n]) % MOD
    else:
        # N is odd
        product = 1
        for i in range(1, n):
            product = (product * dp[i]) % MOD
        dp[n] = product

# Generate the outputs for each query
outputs = [dp[n] for n in queries]

# Print the outputs
print("\n".join(map(str, outputs)))
