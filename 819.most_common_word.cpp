/**
 * Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
 *
 * Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
 *
 *
 *
 * Example:
 *
 * Input:
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation:
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"),
 * and that "hit" isn't the answer even though it occurs more because it is banned.
 *
 *
 * Note:
 *
 * 1 <= paragraph.length <= 1000.
 * 0 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation symbols.
 */

/**
 * 1. 把停用词放入到set中就可以判断是否在停用词列表中了
 * 2. 使用istringstram就可以按照空格进行文本切割了
 *
 *    ```
 *      istringstream iss(paragraph);
 *      string t;
 *      while (iss >> t) {
 *      }
 *     ```
 *
 * 3. 把字符串全部转成小写
 *
 *    ```
 *    transform(b.begin(), b.end(), b.begin(), ::tolower);
 *    ```
 *
 * 4. 判断是否为小写
 *
 *    ```
 *    isalpha(s)
 *    ```
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {

        // 处理停用词
        unordered_set<string> ban;
        for (auto b : banned) {
            transform(b.begin(), b.end(), b.begin(), ::tolower);
            ban.insert(b);
        }

        // 处理输入词
        for (char &p: paragraph) {
            p = isalpha(p) ? (char) tolower(p) : ' ';
        }

        unordered_map<string, int> _table;
        int mn = 0, n = 0;
        string ret;

        // 统计
        istringstream iss(paragraph);
        string t;
        while (iss >> t) {
            if (!ban.count(t)) {
                n = ++_table[t];

                if (n > mn) {
                    mn = n;
                    ret = t;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution s;

    string p1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> b1 = {"hit"};

    assert(s.mostCommonWord(p1, b1) == "ball");

    string p2 = "";
    vector<string> b2 = {};

    assert(s.mostCommonWord(p2, b2) == "");

    return 0;
}