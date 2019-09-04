/**
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 *
 * Example 1:
 *
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * Example 2:
 *
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * Example 3:
 *
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 */

/**
 * 思路很简单，每次记录余数，然后当遇到重复的余数时，就说明商的循环开始了
 *
 * 所以使用一个map来记录 余数=>位置
 * 当遇到重复余数时在此位置前和商的最后加上括号
 *
 * 这道比较繁琐的地方是：
 *
 * 1 当除数或者被除数一个负数的时候，结果为负数。但是当商为0时，结果还是0没有负号。例(7, -12) == "-0.58(3)" 而（0, -5) == "0"
 * 2 因为除数和被除数有可能为负数，而最后当计算过程中是按绝对值计算的，所以应该使用long类型
 * 3 只有当有小数部分当时候才有"."号。如 (2, 3) == "0.(6)" 而(2, 1) == "2"没有点号
 */


#include <string>
#include <unordered_map>
#include <map>

#include <assert.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret;
        int flag = 1;

        long num = (long) numerator;
        long den = (long) denominator;

        if (num < 0) {
            num = -num;
            flag = flag * -1;
        }

        if (den < 0) {
            den = -den;
            flag = flag * -1;
        }

        long tt = num / den;
        long td = num % den;

        if (flag == -1 && (td > 0 || tt > 0)) {
            ret.push_back('-');
        }

        ret.append(to_string(tt));

        if (td == 0) {
            return ret;
        }

        ret.push_back('.');

        long i = ret.size();
        unordered_map<long, long> table;
        unordered_map<long, long>::iterator idx;

        while (td != 0) {
            tt = td * 10 / den;

            idx = table.find(td);

            if (idx == table.end()) {
                table.insert(pair<int, int>(td, i));
                ret.append(to_string(tt));
                i++;
            } else {
                ret.insert(ret.begin() + idx->second, '(');
                ret.push_back(')');

                return ret;
            }

            td = td * 10 % denominator;
        }

        return ret;
    }
};

int main() {
    Solution s;

    assert(s.fractionToDecimal(1, 6) == "0.1(6)");
    assert(s.fractionToDecimal(0, -5) == "0");
    assert(s.fractionToDecimal(7, -12) == "-0.58(3)");
    assert(s.fractionToDecimal(2, 3) == "0.(6)");
    assert(s.fractionToDecimal(2, 1) == "2");
    assert(s.fractionToDecimal(-50, 8) == "-6.25");
    assert(s.fractionToDecimal(4, 333) == "0.(012)");

    return 0;
}





