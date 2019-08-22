/**
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 * 
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */

/**
 * 使用单调递增栈的思路：
 *
 *  遍历原始数组num，当前的元素用i表示
 *
 *  如果栈顶的数字小于等于i，则把i添加到单调栈内
 *  如果栈顶的数字大于i，则把栈顶的元素弹出
 *
 *  在每次栈顶元素弹出时，需要记录总共弹出的个数。当达到k时，说明已经满足最后的结果了，之后把剩余的字符串拼接到栈中即可
 *
 *  如果在num遍历完成后，弹出的个数还没有达到要求，则从栈顶弹出差的个数
 *
 */
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0, size = num.length(), keep = size - k;
        string ret;

        while (i < size) {
            if (ret.empty() || ret.back() < num[i] || k <= 0) {
                ret += num[i++];
            } else {
                ret.pop_back();
                k--;
            }
        }

        // 对于s.removeKdigits("123", 2)，原始字符串就是递增的，需要调整尺寸移除调末尾元素
        ret.resize(keep);

        ret.erase(0, ret.find_first_not_of('0'));
        return ret.empty() ? "0" : ret;
    }
};

int main() {
    Solution s;

    assert(s.removeKdigits("1432219", 3) == "1219");
    assert(s.removeKdigits("10000200", 1) == "200");
    assert(s.removeKdigits("12", 2) == "0");

    return 0;
}