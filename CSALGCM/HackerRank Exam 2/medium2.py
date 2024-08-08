#The BorderRunner Protocol
def solve(n,r,k,implants):
    # TODO
    INF = int(1e18)
    dp = [-INF] * (r + 1)
    dp[r] = 0  # At full resistance, the initial power is 0
    
    for i in range(1, n+1):
        # Update the dp array in reverse to avoid overcounting the same item
        p, rCost = implants[i-1]
        eP = p * k
        eResCost = rCost * k
        newDp = dp[:]
        
        for currentRes in range(r+1):
            if currentRes > rCost:
                newDp[currentRes - rCost] = max(newDp[currentRes - rCost], dp[currentRes] + p)
                
        for currentRes in range(r+1):
            if currentRes > eResCost:
                newDp[currentRes - eResCost] = max(newDp[currentRes - eResCost], dp[currentRes] + eP)
                
        dp = newDp
    
    # The result is the maximum power achievable with any resistance left
    return max(dp)
