#include <string>
#include <vector>

#include <iostream>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        string ans = strs[0];

        for (const auto &str : strs)
        {
            auto i = 0;
            while (i < str.size() && i < ans.size())
            {
                if (str[i] != ans[i])
                {
                    ans = ans.substr(0, i);
                    break;
                }

                i++;
            }

            ans = ans.substr(0, i);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<string> e1 = {"flower", "flow", "flight"};
    assert(s.longestCommonPrefix(e1) == "fl");

    vector<string> e2 = {"dog", "racecar", "car"};
    assert(s.longestCommonPrefix(e2) == "");

    vector<string> e3 = {"aa", "a", "aaaa"};
    assert(s.longestCommonPrefix(e3) == "a");
}