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
 * 和设计dp[i][j]代表到达[i, j]位置总共的路径个数不同
 * 
 * 我们设计dp[i]代表某一行的某个位置总路径个数，然后逐行计算
 * 
 * 在遍历某一行的时候，在未计算到i点时，
 *   dp[i]代表i位置上面一个点的路径数
 *   dp[i-1]代表i位置左面一个点的路径数
 * 所以dp[i] = dp[i] + dp[i-1]
 * 
 * 而最后结果则为
 * dp[m]
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

        vector<int> dp(m, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[j] += dp[j - 1];
            }
        }

        return dp[m - 1];
    }
};

int main()
{
    int m = 0, n = 0;

    auto r = Solution().uniquePaths(m, n);

    cout << r << endl;
}