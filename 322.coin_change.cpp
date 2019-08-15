/**
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * Example 2:
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

/**
 * 假设有硬币 1, 2, 5 求目标值 11
 * 
 * 凑成 11的上一步只能是 (11-1) = 10, (11-2) = 9, (11-5) = 6
 * 而10, 9, 6 的求解方式也是同样的，所以此问题有最优子结构
 * 画成树为
 *                11
 *      10        9       6
 *    9 8 5     8 7 4   5 4 1
 * 
 * 设计dp[i]代表目标值为i的时候，所需的最少硬币个数
 * 所以 dp[i] = min(dp[i-1]+1, dp[i-2]+1, dp[i-5]+1)
 * 
 * 注意两种边界条件
 * 1. 当i-1, i-2, i-5有小于零的情况，说明目标值达不到单个硬币的面额，则不参与比较
 * 2. 当i-1, i-2, i-5有INT_MAX的情况，说明无法完全分配，则不参与比较
 * 3. 如果以上三个同时小于零则dp[i]，说明没法完全分配，则标记为特殊值INT_MAX
 * 4. 如果以上三个同时为INT_MAX，说明全部选择均无法完全分配，依旧标记为INT_MAX
 * 
 * 如果判断是否能正好分配：
 *   如果dp[amount]=INT_MAX说明最后无法分配
 *   需要注意的是：并不意味着dp中有INT_MAX就说明无法分配，因为有可能coins=[2]
 *   这种情况下4是可以完全分配的，3是不行的
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);

        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;

            for (auto coin : coins)
            {
                if (coin > 0 && i - coin >= 0 && dp[i - coin] < INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> conis = {1, 2, 5};
    int amount = 11;

    auto r = Solution().coinChange(conis, amount);

    cout << r << endl;
    return 0;
}