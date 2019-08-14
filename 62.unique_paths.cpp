/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * Example 2:
 * 
 * Input: m = 7, n = 3
 * Output: 28
 */

/**
 * 整体思路：
 *   如果想要到达[m, n]这个位置，则上一步只可能是[m-1, n]或则[m, n-1]
 * 
 * 设计dp[i][j]代表到达[i, j]位置总共的路径个数
 * 则 dp[i][j] = dp[i][j-1] + dp[i-1][j]
 * 
 * 所以最后的结果是dp[m-1][n-1]
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i - 1 < 0 && j - 1 < 0)
                {
                    dp[i][j] = 1;
                }
                else if (i - 1 < 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (j - 1 < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main()
{
    int m = 7, n = 3;

    auto r = Solution().uniquePaths(m, n);

    cout << r << endl;
}