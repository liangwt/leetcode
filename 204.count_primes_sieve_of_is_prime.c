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
#include <stdio.h>

int countPrimes(int n);
bool is_prime(int n);

int main()
{
    printf("an: %d\n", countPrimes(10));
    return 0;
}

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int countPrimes(int n)
{
    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (is_prime(i))
            l++;
    }

    return l;
}