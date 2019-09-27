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

/**
 * 首先说题目，求一个数组的最长递增子序列长度
 *
 * 题目包含两个点：
 *
 * 1. 子序列可以不是连续的
 * 2. 整个子序列是递增的
 *
 * 例如 [10,9,2,5,3,7,101,18] 的最长递增子序列就是[2,3,7,101]
 *
 * **下面说解题思路**
 *
 * 对于 1, 5, 3, 4, 6, 9, 7, 8
 *
 * 假设一个最长子序列以8结束，那么的8这个元素前一个元素必然是在8之前且比8小的元素
 * 即有可能时1，5，3，4，6，7
 *
 * 推论可得：对于任意以i结束的最长子序列，其前一个元素为在i之前且比i小的一个元素
 *
 * 所以可以得到一颗树
 *
 * ```
 *                           8
 *      1       5       3       4       6         7
 *             1        1      1 3   1 5 3 4   1 5 3 4 6
 * ```
 *
 * 对于以8结束的最长子序列长度，则为其所有子节点（1，5，3，4，6，7）中最长的加一
 *
 * 可以看出对于以8结束的最长子序列被分割成了更细小的子问题，且子问题是相同的，所以我们说此问题具有最优子结构，且具有重叠子问题
 *
 * 我们设计 dp[i] 代表以i结束的最长子序列长度，注意此处i为在数组中的索引，而非值
 *
 * 由上面的树可知 dp[7] = max(dp[0], dp[1], dp[2], dp[3], dp[4], dp[6]) + 1
 *
 * 而dp[0], dp[1], dp[2], dp[3], dp[4], dp[6]的值不取决与dp[7]的选择
 *
 * 推广到每一个元素dp[i] = max(dp[j]) + 1 | {nums[i] > nums[j]}
 *
 * 我们从底向上的求解
 *
 * ```cpp
 * dp[0] = 1
 * dp[1] = max(dp[0]) + 1 = 2
 * dp[2] = max(dp[0]) + 1 = 2
 * dp[3] = max(dp[0], dp[2]) + 1 = 3
 * dp[4] = max(dp[0], dp[1], dp[2], dp[3]) + 1 = 4
 * ...
 * ```
 *
 * 注意最后得到的结果并不是dp[7]，而是dp数组中的最大值，因为dp[7]代表的是包含最后一个元素的最长子序列，而整个数组的最长子序列有可能不包含最后一个元素
 *
 */

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int r = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            r = max(r, dp[i]);
        }

        return r;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(s.lengthOfLIS(n1) == 4);

    vector<int> n2 = {1, 5, 3, 4, 6, 9, 7, 8};
    assert(s.lengthOfLIS(n2) == 6);

    return 0;
}