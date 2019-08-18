/**
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * Example 2:
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */

/**
 * 阶乘最后零的个数取决于n中包含的5的个数
 */

#include <assert.h>

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int r = 0;
        while (n > 0)
        {
            r += n / 5;
            n /= 5;
        }
        return r;
    }
};

int main()
{
    Solution s;
    assert(s.trailingZeroes(5) == 1);
    assert(s.trailingZeroes(2) == 0);

    return 0;
}