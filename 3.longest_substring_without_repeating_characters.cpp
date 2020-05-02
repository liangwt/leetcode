/**
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: "abcabcbb"
 *
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * Example 2:
 * 
 * Input: "bbbbb"
 *
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 * 
 * Input: "pwwkew"
 *
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 *              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
 * 逐个遍历字符串的每一个位置，如果遇到之前已经遇到过的字符则需要从上一个相同的位置开始重新计算，所以使用一个map来存储,map的键是字符，值是上一次出现的位置
 *
 * 同时维护一个left，它代表当前正在拼接的无重复的字符串最左端位置，所以长度为i-left+1
 *
 * 当遇到一个首次出现的字符，把它加入到map中
 * 当遇到不是首次出现的字符，需要通过map找到上一次出现的位置，然后还得判断上一次出现的位置是不是在left和i中间
 * 此时更新left，并计算一次字符串最大长度
 *
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> table;
        unordered_map<char, int>::const_iterator idx;

        int ans = 0, left = 0, right = 0, len = s.size();
        char ss;

        while (right < len)
        {
            ss = s[right];
            idx = table.find(ss);

            if (idx != table.end())
            {
                left = max(left, idx->second + 1);
            }

            ans = max(ans, right - left + 1);

            table[ss] = right;
            right++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
    assert(s.lengthOfLongestSubstring("") == 0);
    assert(s.lengthOfLongestSubstring(" ") == 1);
    assert(s.lengthOfLongestSubstring("abba") == 2);

    return 0;
}