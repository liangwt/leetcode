/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 * Example 2:
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 */

/**
 * 和house robber差不多
 *
 * 考虑第一个房间，有两种可能，选择或者不选
 * 如果选择了第一个房间就不能选择最后一个房间，如果不选第一个房间就可以选择最后一个房间（只是可以，不是一定要选）
 *
 * 所以按照选择第一个房间不选最后一个房间求解最大值
 * 按照不选择第一个房间，最后一个房间可以任选求解最大值
 *
 * 以上两种结果的最大值就是最终结果
 */

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        long len = nums.size();

        if (len == 0) {
            return 0;
        }

        if (len == 1) {
            return nums[0];
        }

        if (len == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp1(nums.size());
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        for (int i = 2; i < len - 1; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        vector<int> dp2(nums.size());
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < len; i++) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }

        return max(dp1[len - 2], dp2[len - 1]);
    }
};

int main() {
    Solution s;

    vector<int> n1 = {2, 3, 2};
    assert(s.rob(n1) == 3);

    vector<int> n2 = {1, 2, 3, 1};
    assert(s.rob(n2) == 4);

    vector<int> n3 = {};
    assert(s.rob(n3) == 0);

    vector<int> n4 = {1, 2};
    assert(s.rob(n4) == 2);

    return 0;
}