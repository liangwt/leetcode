// dp[i] 第i天的累计收益

// 目前持有一支股 dp[i][0]:
// 昨天就已经持有的dp[i-1][0]、今天买的dp[i-1][2] - prices[i]
// dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i])

// 目前不持有，并且处于冷冻期 dp[i][1]:
// 只能是今天卖的
// dp[i][1] = dp[i-1][0] + prices[i]

// 目前不持有，并且不处于冷冻期 dp[i][2]:
// 昨天就不持有，或者昨天卖的
// dp[i][2] = max(dp[i-1][2], dp[i-1][1])

// 初始值，第0天
// 目前持有一支股 dp[0][0] 只能是当天买的  dp[0][0] = -prices[0]
// 目前不持有，并且处于冷冻期，是不可能的    dp[0][1] = 0
// 目前不持有，并且不处于冷冻期            dp[0][2] = 0

// 最终结果 max(dp[n][0], dp[n][1], dp[n][2])，dp[n][0] 无意义，所以max( dp[n][1], dp[n][2])

#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        if (prices.empty())
        {
            return 0;
        }

        int a = -prices[0]; // dp[i-1][0]
        int b = 0;          // dp[i-1][1]
        int c = 0;          // dp[i-1][2]

        for (int i = 1; i < prices.size(); i++)
        {
            int t = a + prices[i];
            a = max(a, c - prices[i]);
            c = max(c, b);
            b = t;
        }

        return max(b, c);
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 2, 3, 0, 2};
    assert(s.maxProfit(n1) == 3);

    vector<int> n2 = {};
    assert(s.maxProfit(n2) == 0);
}