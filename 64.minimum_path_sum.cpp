/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        int len_x = (int) grid.size();
        int len_y = (int) grid[0].size();

        vector<vector<int>> dp(len_x, vector<int>(len_y, 0));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < len_x; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < len_y; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < len_x; ++i) {
            for (int j = 1; j < len_y; ++j) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }

        return dp[len_x - 1][len_y - 1];
    }
};

int main() {
    Solution s;

    vector<vector<int>> g1 = {};
    assert(s.minPathSum(g1) == 0);

    vector<vector<int>> g2 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    assert(s.minPathSum(g2) == 7);

    return 0;
}