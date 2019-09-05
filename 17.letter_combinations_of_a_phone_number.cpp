/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 *
 * Example:
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be in any order you want
*/

/**
 * 对于输入23来说
 *
 * 第一个可选择的2对应 a、b、c，再次基础上3可选择的是 d、e、f
 * 所以构成了一棵树
 *            ''
 *     a      b      c
 *   d e f  d e f  d e f
 *
 * 使用dfs每一个到达叶子节点的路径就是最后结果，把它加入到最后结果的数组中
 *
 */

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<char, vector<char>> _table = {
        {'1', {}},
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    void _helper(const string &digits, int str_idx, string ss, vector<string> &result) {
        if (str_idx == digits.size() && !ss.empty()) {
            result.push_back(ss);
        }

        for (auto s : _table[digits[str_idx]]) {
            _helper(digits, str_idx + 1, ss + s, result);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        _helper(digits, 0, "", result);
        return result;
    }
};

int main() {
    Solution s;

    vector<string> r1 = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(s.letterCombinations("23") == r1);

    vector<string> r2 = {"d", "e", "f"};
    assert(s.letterCombinations("3") == r2);

    vector<string> r3 = {};
    assert(s.letterCombinations("") == r3);

    return 0;
}