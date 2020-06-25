#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<char, vector<string>> table;
    unordered_map<string_view, bool> mem;

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (const auto &word : wordDict)
        {
            table[word[0]].push_back(word);
        }

        return helper(string_view(s));
    }

    bool helper(string_view s)
    {
        if (s.empty())
        {
            return true;
        }

        if (mem.find(s) != mem.end())
        {
            return mem[s];
        }

        auto idx = table.find(s[0]);
        if (idx == table.end())
        {
            mem[s] = false;
            return false;
        }

        for (const auto &word : table[s[0]])
        {
            if (s.substr(0, word.size()) == word)
            {
                bool ans = helper(s.substr(word.size()));
                if (ans == true)
                {
                    mem[s] = true;
                    return true;
                }
            }
        }

        mem[s] = false;
        return false;
    }
};

int main()
{
    string s1 = "leetcode";
    vector<string> w1 = {"leet", "code"};
    assert(Solution().wordBreak(s1, w1));

    string s2 = "applepenapple";
    vector<string> w2 = {"apple", "pen"};
    assert(Solution().wordBreak(s2, w2));

    string s3 = "catsandog";
    vector<string> w3 = {"cats", "dog", "sand", "and", "cat"};
    assert(!Solution().wordBreak(s3, w3));

    string s4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> w4 = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    assert(!Solution().wordBreak(s4, w4));
}