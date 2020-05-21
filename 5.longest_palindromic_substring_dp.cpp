#include <string>
#include <vector>

#include <assert.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int start = 0, end = 0;

        for (int j = 0; j < len; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                int l = j - i;

                switch (l)
                {
                case 0:
                    dp[i][j] = true;
                    break;
                case 1:
                    dp[i][j] = (s[i] == s[j]);
                    break;
                default:
                    if (s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && (l > end - start))
                {
                    start = i;
                    end = j;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main()
{
    Solution s;

    assert(s.longestPalindrome("abcba") == "abcba");
    assert(s.longestPalindrome("cbbd") == "bb");
    assert(s.longestPalindrome("") == "");

    return 0;
}