/**
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
 */
#include "include/utils.h"
#include <stdio.h>

int rob(int *nums, int numsSize);

int main()
{
    int nums1[] = {2, 7, 9, 3, 1};
    printf("an: %d\n", rob(nums1, 5));
    int nums2[] = {1, 2, 3, 1};
    printf("an: %d\n", rob(nums2, 4));
    // 7,       6,       6
    int nums3[] = {1, 7, 3, 1, 6, 3, 4, 6, 1};
    printf("an: %d\n", rob(nums3, 9));
}

/**
 * 状态:
 * f(j): 第j个元素时的最优选择
 * 
 * 状态转移方程:
 * f(j) = max(f(j-2) + S[j], f(j-1));
 * 
 * 边界条件
 * f(0) = S[0];
 * f(1) = MAX(S[0], S[1]);
 */
int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }
    if (numsSize == 1)
    {
        return nums[0];
    }
    if (numsSize == 2)
    {
        return I_MAX(nums[0], nums[1]);
    }
    int f[numsSize];
    f[0] = nums[0];
    f[1] = I_MAX(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++)
    {
        f[i] = I_MAX(f[i - 2] + nums[i], f[i - 1]);
    }

    return f[numsSize - 1];
}