/**
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * Input: 4
 * Output: 2
 * Example 2:
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 *              the decimal part is truncated, 2 is returned.
 */

/**
 * 牛顿迭代法
 * 
 * 参考：https://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
 * 
 * 判断xi是否是f(x)=0的解有两种方法：
 * 一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi
 */

#include <assert.h>
#include <math.h>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6)
        {
            pre = res;
            res = (res + x / res) / 2;
        }

        return int(res);
    }
};

int main()
{
    Solution s;

    assert(s.mySqrt(0) == 0);
    assert(s.mySqrt(4) == 2);
    assert(s.mySqrt(8) == 2);
    assert(s.mySqrt(2147483647) == 46340);

    return 0;
}