#include <stdio.h>
#include <limits.h>

int reverse(int x);

int main()
{
    printf("an: %d\n", reverse(-123));
    printf("an: %d\n", reverse(1534236469));
}

int reverse(int x)
{
    int i, t, r = 0;

    while (x != 0)
    {
        i = x % 10;
        if (r > INT_MAX / 10 || (r == INT_MAX / 10 && i > 7))
            return 0;

        if (r < INT_MIN / 10 || (r == INT_MIN / 10 && i < -8))
            return 0;

        r = r * 10 + i;
        x = x / 10;
    }

    return r;
}