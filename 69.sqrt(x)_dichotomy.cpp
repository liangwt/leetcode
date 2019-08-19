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
 * 求一个数的平方根，可以使用二分法逐个测试中间值的平方是不是等于目标值
 * 如果小于目标值说明需要把左值移动到mid
 * 如果大于目标值说明需要把右值移动到mid
 * 
 * 其中几个细节需要注意：
 * 1. 对于left 和 right的中间值 如果用 mid=(left+right)/2 是有溢出风险的
 *    所以mid=left+(right-left)/2是比较合理的
 * 2. 对比中间值mid的平方时，如果使用mid * mid == x的话是有溢出风险的，
 *    所以需要对比 mid == x / mid来避免
 * 3. 一个数的开方不会大于 x/2+1 所以右值从 x/2+1 开始即可
 */

#include <assert.h>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        int left = 1, right = x / 2 + 1;
        int mid, dest;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            dest = x / mid;

            if (mid == dest)
            {
                return mid;
            }

            if (mid > dest)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return right;
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