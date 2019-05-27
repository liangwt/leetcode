/**
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index number 2.
 * Example 2:
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak element is 2,
 *              or index number 5 where the peak element is 6.
 * Note:
 *
 * Your solution should be in logarithmic complexity.
*/
#include <stdio.h>

int findPeakElement(int *nums, int numsSize);

int main() {
    int nums[] = {1, 2, 1, 3, 5, 6, 4};

    int r = findPeakElement(nums, sizeof(nums) / sizeof(int));
    printf("ans: %d\n", r);
}

/**
 * 最简单的思路，按个遍历每一个元素，如果这个元素前一元素和后一个元素都比自己小，那么这个点就是极大值点
 *
 * 需要考虑的是一些边界条件
 * 1 当元素只要一个时，那这个元素就是极大值
 * 2 判断两端元素是否满足极大值条件
 * 3 按照常规判断即可，即 nums[i] > nums[i - 1] && nums[i] > nums[i + 1]
 *
 * 但是题目中要求的是使用对数复杂度，此思路复杂度为O(n)
 *
 */
int findPeakElement(int *nums, int numsSize) {
    if (numsSize == 1) {
        return 0;
    }

    if (nums[0] > nums[1]) {
        return 0;
    }

    if (nums[numsSize - 1] > nums[numsSize - 2]) {
        return numsSize - 1;
    }

    int i = 0;

    for (i = 1; i < numsSize - 1; ++i) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            break;
        }
    }

    return i;

}

