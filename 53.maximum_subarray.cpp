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
 */

#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], pre = nums[0];

        for(int i = 1; i < nums.size(); i++){
            pre = max(pre + nums[i], nums[i]);
            mx = max(mx, pre);
        }

        return mx;
    }
};

int main() {
    Solution
    s;

    vector<int> n1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(s.maxSubArray(n1) == 6);

    vector<int> n2 = {-1};
    assert(s.maxSubArray(n2) == -1);

    return 0;
}
