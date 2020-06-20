#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int x = s.size();
        int y = p.size();

        vector<vector<bool>> dp(x + 1, vector<bool>(y + 1, false));
        dp[0][0] = true;

        auto m = [&](int i, int j) {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        for (int i = 0; i <= x; ++i)
        {
            for (int j = 1; j <= y; ++j)
            {
                bool t = true;

                if (p[j - 1] == '*')
                {
                    if (m(i, j - 1))
                    {
                        t = dp[i - 1][j] || dp[i][j - 2];
                    }
                    else
                    {
                        t = dp[i][j - 2];
                    }
                }
                else
                {
                    if (m(i, j))
                    {
                        t = dp[i - 1][j - 1];
                    }
                    else
                    {
                        t = false;
                    }
                }

                dp[i][j] = t;
            }
        }

        return dp[x][y];
    }
};

int main()
{
    Solution s;

    assert(!s.isMatch("aa", "a"));
    assert(s.isMatch("aa", "a*"));
    assert(s.isMatch("ab", ".*"));
    assert(s.isMatch("aab", "c*a*b"));
    assert(!s.isMatch("mississippi", "mis*is*p*."));
}