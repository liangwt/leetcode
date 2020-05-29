/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * Example 2:
 *
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *              Total amount you can rob = 2 + 9 + 1 = 12.
 *
 */

/**
 * 对于大于等于三个房子数的情况
 *
 * 设dp[i] 代表前i个房子能获取到到最大值
 *
 * 所以对于第i个房子有两张选择，一种是选择自己，所以前面一个位置(i-1)就不能选了，另一种是不选择自己，所以最大值一定在前一个位置
 * 对于第一种情况，结果为dp[i-2]+nums[i]，对于第二种情况结果为dp[i-1]，取两个里面的最大值即可
 *
 * 所以：
 *  dp[0] = nums[0]
 *  dp[1] = max(dp[0], nums[1])
 *  dp[2] = max(dp[0] + nums[2], dp[1])
 *  ...
 *  dp[i] = max(dp[i-2] + nums[i], dp[i-1])
 *
 * 最后的结果就是dp[nums.size()-1]
 */

#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        if (nums.size() == 1)
        {
            return nums[0];
        }

        int len = nums.size();

        vector<int> dp = vector<int>(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < len; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 2, 3, 1};
    assert(s.rob(n1) == 4);

    vector<int> n2 = {2, 7, 9, 3, 1};
    assert(s.rob(n2) == 12);

    vector<int> n3 = {2, 1, 1, 9, 3, 1};
    assert(s.rob(n3) == 12);

    vector<int> n4 = {};
    assert(s.rob(n4) == 0);

    vector<int> n5 = {2};
    assert(s.rob(n5) == 2);

    return 0;
}