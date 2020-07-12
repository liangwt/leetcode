#include <vector>

using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        // dp[i][j] 从 i,j 到终点所需要的路径和
        // 对于 (i,j) 来说，要走到终点:
        //   要么向右走，此时取决于dp[i][j+1]
        //   要么向下走，此时取决于dp[i+1][j]
        // 只需要选择向右和向下里面的最小值，同时让 dp[i][j] + dungeon[i][j]  > min 即可

        if (dungeon.empty() || dungeon[0].empty())
        {
            return 1;
        }

        int y = dungeon.size(), x = dungeon[0].size();

        vector<vector<int>> dp(y + 1, vector<int>(x + 1, INT_MAX));
        dp[y - 1][x] = 1;
        dp[y][x - 1] = 1;

        for (int i = y - 1; i >= 0; i--)
        {
            for (int j = x - 1; j >= 0; j--)
            {
                dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};

int main()
{
    Solution s;

    vector<vector<int>> n1 = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    assert(s.calculateMinimumHP(n1) == 7);
}