#Requiem For a Recurrence

"""
This function solves a test case.

Parameters:
n : int - argument to the function
a : int - base case value
b : int - base case value
c : int - base case value

Returns the value of F(n)
"""
def solve(n,a,b,c):
    # TODO
    MOD = 10**9 + 7
    
    # Base cases
    if n == 0:
        return c
    elif n == 1:
        return b
    elif n == 2:
        return a
    
    # Initialize the first three values
    F = [c, b, a]
    
    # Compute F(n) iteratively for n >= 3
    for i in range(3, n + 1):
        next_value = (F[2] * F[1] + F[0]) % MOD
        F[0], F[1], F[2] = F[1], F[2], next_value
    
    return F[2]

n, a, b, c = list(map(int,input().strip().split(" ")))

print(solve(n,a,b,c))