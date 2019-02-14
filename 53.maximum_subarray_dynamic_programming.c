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
#include <stdio.h>
#include "include/utils.h"

int main()
{
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = 9;
    printf("an: %d\n", maxSubArray(nums, numsSize));
}

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
int maxSubArray(int *nums, int numsSize)
{
    int local = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        local = I_MAX(local + nums[i], nums[i]);
        max = I_MAX(local, max);
    }

    return max;
}
