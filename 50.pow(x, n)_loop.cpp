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
 * @update: 2020-05-11
 * 
 * 对于任意一个数 n 用二进制数计算可得
 * n = $2^{i_{0}} + 2^{i_{1}} + ... + 2^{i_{k}}$
 * 
 * 所以对于任意一个 $x^{n}$，可得
 * $x^{n}$
 * = $x^{2^{i_{0}} + 2^{i_{1}} + ... + 2^{i_{k}}}$
 * = $x^{2^{i_{0}}} * x^{2^{i_{1}}} * ... * x^{2^{i_{k}}}$
 * 
 * 也就是说对于n的二进制，如果某一位为1，则对应的$x^{i_{k}}$需要计算到最后结果去
 **/ 

#include <assert.h>
#include <iostream>

#define EPSILON (0.001)

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double t = 1.00;
        int i = n;

        while (i)
        {
            // 把奇数情况记在额外变量t里， 最后t = 1 * x * x ^ 2... * x ^ y
            // 而偶数情况不断的使x翻倍，最后 x = (((x)^2)^2)^2
            // 且最后一次 i = 1，所以最后的结果就为
            // t * x = (((x)^2)^2)^2 * 1 * x * x ^ 2... * x ^ y
            //       = x ^ n
            if (i % 2 != 0)
            {
                t *= x;
            }

            x *= x;
            i /= 2;
        }

        return n > 0 ? t : 1 / t;
    }
};

int main()
{
    Solution s;
    assert((s.myPow(2.00000, 10) - 1024.00000) < EPSILON);
    assert((s.myPow(2.10000, 3) - 9.26100) < EPSILON);
    assert((s.myPow(2.00000, -2) - 0.25000) < EPSILON);

    return 0;
}