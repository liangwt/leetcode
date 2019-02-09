#include <stdio.h>

int hammingDistance(int x, int y);

int main()
{
    int l = hammingDistance(1, 4);
    printf("an: %d\n", l);
}

int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int l = 0;
    while (n != 0)
    {
        l++;
        n &= (n - 1);
    }

    return l;
}