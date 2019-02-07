/**
 * 
 * Count the number of prime numbers less than a non-negative number, n.
 * Example:
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */
#include <stdbool.h>

int countPrimes(int n);

int main()
{
    return 0;
}

int countPrimes(int n)
{
    if (n == 0)
    {
        return 0;
    }

    bool flags[n];
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        flags[i] = true;
    }

    for (int j = 2; j < n; j++)
    {
        if (flags[j])
        {
            ret++;
            for (int k = 2; k * j < n; k++)
            {
                flags[k * j] = false;
            }
        }
    }

    return ret;
}