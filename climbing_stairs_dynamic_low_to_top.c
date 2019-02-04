#include <stdio.h>

int climbStairs(int n);

int main()
{
    printf("an: %d", climbStairs(45));
    return 0;
}

int climbStairs(int n)
{
    int i = 1, j = 1, k = 0, m = 0;

    for (m = 1; m < n; m++)
    {
        k = i;
        i = i + j;
        j = k;
    }

    return i;
}