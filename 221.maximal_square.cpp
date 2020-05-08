/**
 * 设 dp[i][j] 为以i,j为右下角且只包含1的正方形边长
 * 
 * 对于 matrix[i][j] == 1来说
 * 
 * 则 dp[i][j]的大小取决于左dp[i][j-1]，上dp[i-1][j]，左上dp[i-1][j-1]三个位置的值
 * dp[i][j] 为三个位置中最小值加1
 * 
 * 即 
 * dp[y][x] = min(min(dp[y - 1][x - 1], dp[y][x - 1]), dp[y - 1][x]) + 1;
 * 
 * 所以最大面积就为最大边长的乘方
 **/
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }

        int len_y = matrix.size();
        int len_x = matrix[0].size();
        vector<vector<int>> dp(len_y, vector<int>(len_x, 0));

        int ans = 0;

        for (int y = 0; y < len_y; ++y)
        {
            if (matrix[y][0] == '1')
            {
                dp[y][0] = 1;
                ans = max(ans, 1);
            }
        }

        for (int x = 0; x < len_x; ++x)
        {
            if (matrix[0][x] == '1')
            {
                dp[0][x] = 1;
                ans = max(ans, 1);
            }
        }

        for (int y = 1; y < len_y; ++y)
        {
            for (int x = 1; x < len_x; ++x)
            {
                if (matrix[y][x] == '1')
                {
                    dp[y][x] = min(min(dp[y - 1][x - 1], dp[y][x - 1]), dp[y - 1][x]) + 1;
                    ans = max(ans, dp[y][x]);
                }
            }
        }

        return ans * ans;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> m1 = {{'0'}};
    assert(s.maximalSquare(m1) == 0);

    vector<vector<char>> m2 = {};
    assert(s.maximalSquare(m2) == 0);

    vector<vector<char>> m3 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    assert(s.maximalSquare(m3) == 4);
}