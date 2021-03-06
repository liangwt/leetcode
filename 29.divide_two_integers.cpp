/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Example 2:
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Note:
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.
 */

/**
 * 常规思路：
 *   我们不断把除数divisor累加，直到刚好小于被除数dividend，累加的次数就是商
 *  
 * 思路1：
 *
 *   > https://kingsfish.github.io/2017/10/11/Leetcode-29-Divide-Two-Integers/
 *
 *   如上每次增长都是一个除数divisor，增长的速度很慢
 * 
 *   对于一个整数来说，一定可以被转化成二进制形式，所以我们按照二进制逐位增长
 *   这样每次增长的幅度就为2^0, 2^1, 2^2 ..
 *   
 *      在二进制表示的情况下，在进行着如下操作
 *      0 0 0 0 0 0 0  -> 0 0 0 0 0 0 1 -> 0 0 0 0 0 1 1 -> 0 0 0 0 1 1 1 
 *   
 *   于是在某个时刻，最终的数值*除数会大于被除数，此时增长的结果为 1 1 1 1 ... 1 1 1
 *   所以商一定是位于 1 1 1 1 ... 1 1 1 和 1 0 0 0 ... 0 0 0之间
 *  
 *   于是我们把1 0 0 0 ... 0 0 0从倒数第二高位开始逐个把位设置成1，然后继续乘以被除数
 *    1. 如果大于被除数，说明当前位为0
 *    2. 如果小于被除数，说明当前位为1
 *   直到最低位全部设置完成，就得到了最后的商
 * 
 *   举例：
 *     对于16/3来说，先找到2的最高次幂乘以除数刚好大于被除数
 *     3 * ( 2^0 ) = 3
 *     3 * ( 2^1 + 2^0 )= 9
 *     3 * ( 2^2 + 2^1 + 3 * 2^0 ) = 21 > 16
 * 
 *     所以商一定在 1 1 1 和 1 0 0之间
 * 
 *     现在开始从1 0 0 开始增长
 *     3 * ( 2^2 + 2^1 ) = 18 > 16 说明第二位为0
 *     3 * ( 2^2 + 2^0 ) = 15 < 16 说明此位为1
 *     
 *     所以最后的商就是  1 0 1 = 5
 *
 * 思路2：
 *
 *   对于 16/3 来说，16 / 3 = （3 * 2^2 + 3 * 2^0 + 1) / 3 = 2^2 + 2^0 = 5
 *
 *   所以不断让3乘上2的n次(3<<n)，让最后的结果刚好小于16，此时n=2，所以2^2将作为结果的加数之一
 *   之后，让16 - 3 * 2^2 = 4，对4重复上面的步骤，此时n=0，所以2^0将作为结果的加数之一
 *   再让4 - 3 * 2^0 = 1，此时剩余的值已经不够3了所以就得到了最后结果
 */

#include <limits.h>
#include <assert.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX - 1;
        }

        long dividend_long = (long) dividend, divisor_long = (long) divisor, ret = 0;
        int n, flag = 1;

        if (dividend_long < 0) {
            flag *= -1;
            dividend_long = -dividend_long;
        }

        if (divisor_long < 0) {
            flag *= -1;
            divisor_long = -divisor_long;
        }

        while (dividend_long >= divisor_long) {
            n = 0;

            while (dividend_long > divisor_long << (n + 1)) {
                n++;
            }

            ret += 1 << n;
            dividend_long = dividend_long - (divisor_long << n);
        }

        return (int) ret * flag;
    }
};

int main() {
    Solution s;

    assert(s.divide(1, -1) == -1);
    assert(s.divide(10, 3) == 3);
    assert(s.divide(7, -3) == -2);
    assert(s.divide(-2 ^ 31, -1) == 2 ^ 31 - 1);
    assert(s.divide(2 ^ 31 - 1, 1) == 2 ^ 31 - 1);

    return 0;
}