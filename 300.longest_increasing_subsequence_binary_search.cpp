/**
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * 
 * Example:
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
 * Note:
 * 
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp;

        for (size_t i = 0; i < nums.size(); i++)
        {
            // 二分法在dp里找到第一个不小于nums[i]的元素
            int left = 0, right = dp.size() - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (dp[mid] < nums[i])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            // 如果不存在比nums[i]大的元素则把此元素加入到dp数组最后
            if (left >= dp.size())
            {
                dp.push_back(nums[i]);
            }
            // 把第一个不小于nums[i]的元素替换成nums[i]
            else
            {
                dp[left] = nums[i];
            }
        }

        // 最后的dp数组长度就是整个字符串的lis长度，但并不是lis结果，只是长度相等
        return dp.size();
    }
};

int main()
{
    vector<int> nums = {1, 5, 3, 4, 6, 9, 7, 8};

    Solution s;
    int r = s.lengthOfLIS(nums);

    cout << r << endl;
    return 0;
}