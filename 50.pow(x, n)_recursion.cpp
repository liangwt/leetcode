/**
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * Example 2:
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * Example 3:
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * Note:
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */

/**
 * 对于 n 为奇数 x^n = (x^n/2) ^ 2 * x
 * 对于 n 为偶数 x^n = (x^n/2) ^ 2
 * 
 * 所以括号里的算数运算形成递归
 * 
 * 对于n为负数的处理：
 *  不能直接算出 /n/然后得出最后结果的倒数，因为对于-2^31的绝对值，已经对于int类型溢出了
 *  所以在每一层递归中来判断，如果n小于零怎最后返回的结果等于下一层的结果*1/x
 */

#include <assert.h>
#include <iostream>

#define EPSILON (0.0001)

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }

        if (n == 1)
        {
            return x;
        }

        double t = myPow(x, n / 2);
        double r = t * t;

        if (n % 2 == 0)
        {
            return r;
        }

        if (n > 0)
        {
            return r * x;
        }
        else
        {
            return r / x;
        }
    }
};

int main()
{

    Solution s;
    assert((s.myPow(2.00000, 10) - 1024.00000) < EPSILON);
    assert((s.myPow(2.10000, 3) - 9.26100) < EPSILON);
    assert((s.myPow(2.00000, -2) - 0.25000) < EPSILON);
    assert((s.myPow(2.00000, -2147483648) - 0) < EPSILON);

    return 0;
}