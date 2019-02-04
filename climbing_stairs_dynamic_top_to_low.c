#include <stdio.h>

int climbStairs(int n);
int _climbStairs(int n, int *memo);

int main()
{
    printf("an: %d", climbStairs(45));
    return 0;
}

int climbStairs(int n)
{
    int memo[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = -1;
    }

    return _climbStairs(n, memo);
}

int _climbStairs(int n, int *memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        memo[n] = _climbStairs(n - 1, memo) + _climbStairs(n - 2, memo);
    }

    return memo[n];
}