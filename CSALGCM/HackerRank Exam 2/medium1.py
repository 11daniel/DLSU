#The Epic of Alexander The Great

def solve(n, r, s):
    """
    This function solves a test case.

    Parameters:
    n : int        - number of nations
    r : int        - number of armies
    s : array-like - strength for each nation, army count combination

    Returns maximum total strength attainable.
    """
    dp = [[0] * (r + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, r + 1):
            max_strength = 0
            for k in range(1, min(j, len(s[i - 1])) + 1):
                max_strength = max(max_strength, dp[i - 1][j - k] + s[i - 1][k - 1])
            dp[i][j] = max(dp[i - 1][j], max_strength)

    return dp[n][r]

n, r = map(int, input().split())
s = [list(map(int, input().split())) for _ in range(n)]

print(solve(n, r, s))
