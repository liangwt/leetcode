/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output: 321
 * Example 2:
 *
 * Input: -123
 * Output: -321
 * Example 3:
 *
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

/**
 * 首先需要知道在c++中对于负数相除和取余最后的结果都是负数，即 -123/10 = -12、-123/10 = -3
 *
 * 所以求一个数的倒序数很简单，只要不断对原数取余，然后新数乘10加这个余数
 *
 * 这道题最大的难点在于溢出条件
 *
 * 对于正数会在什么时刻溢出：
 *   第一种，新数剩以10之后大于2147483647，即 r > INT_MAX / 10
 *   第二种，新数剩以10之后等于2147483640，这时要加上一个余数，因为INT_MAX = (2147483647) 如果余数大于7了就溢出了
 *
 * 对于负数：
 *   第一种，新数乘以10之后小于-2147483648，即 r < INT_MIN / 10
 *   第二种，新数乘以10刚好等于-2147483640，这时还要加上一个余数（负数），因为INT_MIN = (-2147483648)，所以如果余数小于-8就溢出了
 *
 */

#include <assert.h>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int n = x, r = 0;

        while (n) {
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && n % 10 > 7)) {
                return 0;
            }

            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && n % 10 < -8)) {
                return 0;
            }

            int t = n % 10;
            r = r * 10 + n % 10;
            n = n / 10;
        }

        return r;
    }
};

int main() {
    Solution s;

    assert(s.reverse(123) == 321);
    assert(s.reverse(-123) == -321);
    assert(s.reverse(120) == 21);
    assert(s.reverse(120) == 21);
    assert(s.reverse(INT_MIN) == 0);
    assert(s.reverse(INT_MAX) == 0);
}