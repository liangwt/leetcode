/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

/**
 * 状态
 * f(j)：第j个元素时的最优解
 *
 * 状态转移方程
 * f(j) = max(f(j-1)+S[j], S[j])
 *
 * 最终结果
 * result = max(f(0), f(1), ..., f(n))
 * 
 * @update: 2020-05-03
 * 不用动态规划的思想：
 * 对于某一个位置i，如果在之前的子数组和比0小，说明只会##拖累##当前值的大小，直接抛弃之前的和重新算
 */

#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int t = INT_MIN;
        int ans = INT_MIN;

        for (const auto &num : nums)
        {
            if (t <= 0)
            {
                t = num;
            }
            else
            {
                t += num;
            }
            ans = max(ans, t);
        }

        return ans;
    }
};

int main()
{
    Solution
        s;

    vector<int> n1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(s.maxSubArray(n1) == 6);

    vector<int> n2 = {-1};
    assert(s.maxSubArray(n2) == -1);

    return 0;
}
