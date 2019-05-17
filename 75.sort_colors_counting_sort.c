/**
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 *
 * Example:
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Follow up:
 *
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
**/
#include <stdio.h>

void sortColors(int *nums, int numsSize);

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(int);
    sortColors(nums, numsSize);

    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
}

/**
 * 这种方案是最简单的，使用一个数组记录0，1，2三个颜色的个数
 * 最后按照个数来重新写入nums
 * 但是很明显这个并不是原址（in-place）的
 * 此算法的空间复杂度是O(3)
 *
 *
 * @param nums
 * @param numsSize
 */
void sortColors(int *nums, int numsSize) {
    int tmp[3] = {0, 0, 0};

    for (int i = 0; i < numsSize; ++i) {
        tmp[nums[i]]++;
    }

    int t = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < tmp[i]; ++j) {
            nums[t] = i;
            t++;
        }
    }
}


