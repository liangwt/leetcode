/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * Example 1:
 *
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 *
 * Input: a = -2, b = 3
 * Output: 1
 */

/**
 * 对于两个数的和，145 + 478
 *
 * 如果不算进位得：513
 * 只算进位得：110
 *
 * 所以两个数相加就得 513+110 = 623
 *
 * 两个数不算进位：
 *   1 + 1 = 0, 1 + 0 = 1 0 + 1 = 1 0 + 0 = 0，所以结果就是两个数的异或
 *   即 145^478 = 513
 *
 * 两个数只算进位：
 *
 *   1 + 1 = 1, 1 + 0 = 0, 0 + 1 = 1, 0 + 0 = 0，所以结果就是两个数的与
 *   即 145 & 623 = 11
 *
 * 所以 145 + 478 = 145^478 + 145 & 478 << 1
 */

#include <limits.h>
#include <assert.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b & 0x7fffffff) << 1;

            a = a ^ b;
            b = carry;
        }

        return a;
    }
};

int main() {
    Solution s;

    assert(s.getSum(1, 2) == 3);
    assert(s.getSum(-2, 3) == 1);
    assert(s.getSum(0, 0) == 0);
    assert(s.getSum(INT_MIN, 1) == INT_MIN + 1);
    assert(s.getSum(INT_MAX, -1) == INT_MAX - 1);

    return 0;
}