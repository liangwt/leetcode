/**
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * Example 1:
 *
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 *
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 *
 * Input: s = "paper", t = "title"
 * Output: true
 * Note:
 * You may assume both s and t have the same length.
 */

/**
 * 使用一个字符串作为类型的表达式，初始化为空
 *
 * 逐个遍历字符串的每一个字符并存入到map中
 *
 * 对于map中还没存在的字符，加入到map中，值为递增的一个数字，并在表达式后面加上这个值
 *
 * 对于在map中存在的字符，取出值加入到表达式最后
 *
 * 于是对于egg 我们就可以得到类似122的表达式
 * 对于paper 表达式 12134
 *
 * 最后对比两个字符串的表达式是否相等即可
 *
 */

#include <unordered_map>
#include <string>
#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> s_map;
        string s_idf;

        for (int i = 0; i < s.size(); ++i) {
            auto idx = s_map.find(s[i]);

            if (idx == s_map.end()) {
                s_map[s[i]] = i;
                s_idf.push_back(char(i + 1));
            } else {
                s_idf.push_back(char(idx->second + 1));
            };
        }

        unordered_map<char, int> t_map;
        string t_idf;

        for (int i = 0; i < t.size(); ++i) {
            auto idx = t_map.find(t[i]);

            if (idx == t_map.end()) {
                t_map[t[i]] = i;
                t_idf.push_back(char(i + 1));
            } else {
                t_idf.push_back(char(idx->second + 1));
            };
        }

        return t_idf == s_idf;
    }
};

int main() {
    Solution s;

    assert(s.isIsomorphic("egg", "add"));
    assert(!s.isIsomorphic("foo", "bar"));
    assert(s.isIsomorphic("paper", "title"));
    assert(s.isIsomorphic("", ""));

    return 0;
}