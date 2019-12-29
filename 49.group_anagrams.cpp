/**
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

/**
 * 思路一：
 *
 *   对于两个字符串，如果排序之后即可对比是否有相同的字符
 *   所以只要把二维数组中的每一个字符串排序之后的值作为key，加入到map中即可分类
 *
 * 思路二：
 *
 *   统计字符串中各个字母的个数，然后把这些个数用分隔符分割连接到一起作为key，相同的key的说明两个字符串具有相同的字符
 *
 *   例如 "eat", "tea", "tan"
 *
 *   分别得到
 *
 *   1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
 *   1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
 *   1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0
 *
 *   把他们用#分割拼接到一块
 *   1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0
 *   1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0
 *   1#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#1#0#0#0#0#0#0
 *
 *   对于只有两个字母a和b的话，如果字符串是123的时候，没法区分到底是 a->12, b->3 还是 a->1, b->23
 *   所以需要使用分割进行分割
 */

#include <vector>
#include <string>
#include <unordered_map>
#include "include/header/utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        unordered_map<string, vector<string>> _table;

        for (auto &str:strs) {
            string t = str;
            sort(t.begin(), t.end());
            _table[t].push_back(str);
        }

        vector<vector<string>> result(_table.size());
        int i = 0;

        for (auto &it:_table) {
            result[i++] = it.second;
        }

        return result;
    }
};


int main() {
    Solution s;

    vector<string> s1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> r1 = {
        {"ate", "eat", "tea"},
        {"nat", "tan"},
        {"bat"},
    };
    assert(vector_equal<string>(s.groupAnagrams(s1), r1));

    vector<string> s2 = {};
    assert(s.groupAnagrams(s2) == vector<vector<string>>{});

    return 0;
}