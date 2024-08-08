#Quatromania's Encore

"""
This function solves a test case.

Parameters:
l            : int        - length of quatrum cluster
w            : int        - width of quatrum cluster
d            : int        - depth of quatrum cluster
length_costs : array-like - list of size (l - 1,) containing instability indices
                            of length-wise cuts
width_costs  : array-like - list of size (w - 1,) containing instability indices
                            of width-wise cuts
depth_costs  : array-like - list of size (d - 1,) containing instability indices
                            of depth-wise cuts

Returns:
An integer indicating the total instability of all the permutations of cuts 
possible.
"""
def solve(l,w,d,length_costs,width_costs,depth_costs):
    # TODO
    MOD = int(1e9 
+ 7)
    for i in range(l-1):
        length_costs[i] = [length_costs[i],0]
    for j in range(w-1):
        width_costs[j] = [width_costs[j],1]
    for k in range(d-1):
        depth_costs[k] = [depth_costs[k],2]
        
    cost = length_costs + width_costs + depth_costs
    num_cuts = len(cost)
    g = 2**num_cuts
    memo = [[] for i in range(g)]
    memo[0].extend([0,1,[1,1,1],0])
    
    for t in range(1,g):
        init = False
        for i in range(num_cuts):
            pred = (2**i)^t
            if pred < t:
                d = cost[i][1]
                c = cost[i][0]
                if not init:
                    memo[t].append(memo[pred][0]+1)
                    memo[t].append(memo[t][0] * memo[pred][1])
                    config = memo[pred][2].copy()
                    config[d] += 1
                    memo[t].append(config)
                    memo[t].append(0)
                    init = True
                
                memo[t][3] += (memo[pred][3] + (memo[pred][1]  * c* memo[pred][2][(d+1)%3] * memo[pred][2][(d+2)%3])) % MOD
                memo[t][3] = memo[t][3] % MOD
                
    return memo[-1][3]

l,w,d = list(map(int,input().split(" ")))
length_costs = [int(input()) for i in range(l - 1)]
width_costs = [int(input()) for i in range(w - 1)]
depth_costs = [int(input()) for i in range(d - 1)]

print("{}\n".format(solve(l,w,d,length_costs,width_costs,depth_costs)))