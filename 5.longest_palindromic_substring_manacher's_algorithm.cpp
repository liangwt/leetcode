/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 * 
 * Input: "cbbd"
 * Output: "bb"
 */

/**
 *
 * 设：
 *  i: 字符串当前遍历到位置
 *  id: 触及到最右端的回文串中心位置
 *  mx: 回文串触及到的最右端位置
 *  p<int>: 每一个位置的回文串长度
 *
 * 所以得
 *
 *  j = 2*id - i: 以id为中心，i的对称位置
 *  mx': 以id为中心，id的对称位置
 *
 * --------------------------------
 *  ^    ^     ^     ^    ^
 *  mx'  j    id     i    mx
 *
 * 当i >= mx 时，此时没有任何信息，只能往前寻找回文串
 * 当i < mx 时：
 *    当p[j] < mx - i 时，说明 i 的位置的回文串长度和j的一样于是 p[i] = p[j]
 *    当p[j] >= mx -i 时，说明 i 的位置回文串已经超过了mx'-mx的区间，且i位置的回文串包含了mx，从mx继续往前寻找
 *
 */

#include <string>
#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ss = "#";

        // 先对字符串进行预处理
        for (auto c :s) {
            ss.push_back(c);
            ss.append("#");
        }

        int id = 0, mx = 0, res_len = 0, res_cen = 0;
        vector<int> p(ss.size(), 0);

        for (int i = 0; i < ss.size(); ++i) {
            // 把当前值算进去，然后向两边扩散寻找
            if (i >= mx) {
                p[i] = 1;
            } else {
                if (p[2 * id - i] < mx - i) {
                    p[i] = p[2 * id - i];
                    continue;
                } else {
                    p[i] = mx - i;
                }
            }

            // 从i-p[i] ,, i+p[i]向两边扩散寻找
            while (i + p[i] < ss.size() && i - p[i] >= 0 && ss[i + p[i]] == ss[i - p[i]]) ++p[i];

            // 更新id, mx值
            if (i + p[i] > mx) {
                mx = i + p[i] - 1;
                id = i;
            }

            // 记录结果最大值
            if (res_len < p[i]) {
                res_len = p[i];
                res_cen = i;
            }
        }

        return s.substr((res_cen - res_len + 1) / 2, res_len - 1);
    }
};

int main() {
    Solution s;

    assert(s.longestPalindrome("abcba") == "abcba");
    assert(s.longestPalindrome("cbbd") == "bb");
    assert(s.longestPalindrome("") == "");

    return 0;
}