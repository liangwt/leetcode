#include <assert.h>

class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; i++)
        {
            a = b + c;
            c = b;
            b = a;
        }

        return a;
    }
};

int main()
{
    Solution s;
    assert(s.climbStairs(1) == 1);
    assert(s.climbStairs(2) == 2);
    assert(s.climbStairs(10) == 89);
}