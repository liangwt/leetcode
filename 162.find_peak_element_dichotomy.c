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
#include <math.h>

int findPeakElement(int *nums, int numsSize);

int main() {
    int nums[] = {1, 2, 1, 3, 5, 6, 4};

    int r = findPeakElement(nums, sizeof(nums) / sizeof(int));
    printf("ans: %d\n", r);
}

/**
 * 如果想实现O(lg(n))的复杂度，可以考虑使用二分法
 * 对于两端元素left和right，取中间位置mid = (right - left) / 2 + left = (right + left) / 2
 *  1. 如果mid+1比mid大，说明极大值点位于mid+1或mid+1之后，所以left移动到mid+1
 *  2. 如果mid+1比mid小，说明极大值点位于mid或者mid之前，所以right移动到mid
 *
 * 所以当left和right相遇时，为极大值点
 *
 */
int findPeakElement(int *nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
