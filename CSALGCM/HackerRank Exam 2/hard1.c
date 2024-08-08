// The Razor Crest's Stutter

#include <stdio.h>
#include <string.h>

#define INF 1000000000000000000LL

int e[19][19];
int f[19][19];
long long memo[1 << 19][19];

/*
This function solves one test case.

Parameters:
n : int     - number of repairs
e : int[][] - array of energy increases for each repair, order combination
f : int[][] - array of additional ion modification energy increases for each
                 repair, order combination

Returns the maximum energy capacity attainable.
*/
long long solve(int n)
{
    memset(memo, -1, sizeof(memo));

    long long computeMaxEnergy(int currRepair, int repairCount, int ions)
    {
        if (repairCount == n - ions)
        {
            return 0;
        }

        if (memo[currRepair][ions] != -1)
        {
            return memo[currRepair][ions];
        }

        long long maxEnergy = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!(currRepair & (1 << i)))
            {
                long long energyNoIon = e[i][repairCount] + computeMaxEnergy(currRepair | (1 << i), repairCount + 1, ions);
                if (maxEnergy < energyNoIon)
                {
                    maxEnergy = energyNoIon;
                }

                if (ions < n - 1 && repairCount + 1 < n - ions)
                {
                    long long energyWithIon = e[i][repairCount] + f[i][repairCount] + computeMaxEnergy(currRepair | (1 << i), repairCount + 1, ions + 1);
                    if (maxEnergy < energyWithIon)
                    {
                        maxEnergy = energyWithIon;
                    }
                }
            }
        }

        memo[currRepair][ions] = maxEnergy;
        return maxEnergy;
    }

    return computeMaxEnergy(0, 0, 0);
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &e[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &f[i][j]);
        }
    }

    printf("%lld\n", solve(n));
    return 0;
}
