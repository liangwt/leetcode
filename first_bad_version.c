#include <stdbool.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int i = n;
    while (n > 0)
    {
        if (!isBadVersion(n))
        {
            return i;
        }
        i = n;
        n--;
    }
    return 1;
}