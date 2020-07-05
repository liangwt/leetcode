#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int len_s = s.size(), len_p = p.size();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));

        // dp[0][0]=true s 和模式 p 均为空时，匹配成功；
        // dp[i][0]=false，即空模式无法匹配非空字符串；
        // dp[0][j] 需要分情况讨论：因为星号才能匹配空字符串，
        //  所以只有当模式 p 的前 j 个字符均为星号时，dp[0][j] 才为真。
        dp[0][0] = true;
        for (int j = 0; j < len_p; j++)
        {
            if (p[j] == '*')
            {
                dp[0][j + 1] = true;
            }
            else
            {
                break;
            }
        }

        auto match = [s, p](int i, int j) -> bool {
            if (p[j] == '?')
            {
                return true;
            }

            return p[j] == s[i];
        };

        for (int i = 1; i <= len_s; i++)
        {
            for (int j = 1; j <= len_p; j++)
            {
                if (p[j - 1] != '*')
                {
                    dp[i][j] = match(i - 1, j - 1) ? dp[i - 1][j - 1] : false;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[len_s][len_p];
    }
};

int main()
{
    Solution s;

    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "*") == true);
    assert(s.isMatch("cb", "?a") == false);
    assert(s.isMatch("adceb", "*a*b") == true);
    assert(s.isMatch("acdcb", "a*c?b") == false);
}