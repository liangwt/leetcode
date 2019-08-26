/**
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 *
 * A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
 *
 *
 *
 * If there is no common subsequence, return 0.
 *
 *
 *
 * Example 1:
 *
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 * Example 2:
 *
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 * Example 3:
 *
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 *
 * Constraints:
 *
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 */

/**
 *
 * 采取动态规划的算法
 *
 * 对于两字符串 X = {x1, x2, x3, ... xm} 和 Y = {y1, y2, y3, ... yn}
 *
 * 当 x(m) == y(n)时，两者的LCS为 X(m-1),Y(n-1) 在末尾加上 x(m), y(n)
 *
 * 当 x(m) != y(n)时，两者的LCS为 X(m), Y(n-1) 和 X(m-1), Y(n)中比较长的一个
 *
 * 因此定义c[i, j] 代表 X(i), Y(j)的LCS长度
 *
 * c[i,j] = {
 *
 *   0                               若i=0, j=0
 *   c[i-1, j-1] + 1                 若X(i) == Y(j)
 *   max(c[i - 1, j], c[i, j - 1])   若X(i) != Y(j)
 *
 * }
 *
 */


#include <string>
#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> c(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else {
                    c[i][j] = max(c[i - 1][j], c[i][j - 1]);
                }
            }
        }

        return c[text1.size()][text2.size()];
    }
};

int main() {
    Solution s;

    assert(s.longestCommonSubsequence("abcde", "ace") == 3);
    assert(s.longestCommonSubsequence("abc", "abc") == 3);
    assert(s.longestCommonSubsequence("abc", "def") == 0);
    assert(s.longestCommonSubsequence("", "") == 0);

    return 0;
}