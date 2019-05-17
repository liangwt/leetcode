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
 * 使用两个指针，一个指向开头红色的(0)，一个指向蓝色的(2)
 * 然后遍历数组，当遇到红色时和红色指针交换，并将红色指针移向下一位
 *
 * 当交换红色指针时，因为之前的部分都已经扫描过了，所以不是0，就是1，
 * 在交换完红色之后，即使交换过来，也是已知的，所以当前位置也需要往后移动一位
 *
 * 当遇到蓝色时和蓝色指针交换，并将蓝色指针移向上一位
 *
 * @param nums
 * @param numsSize
 */
void sortColors(int *nums, int numsSize) {
    // 红蓝指针
    int i = 0, j = numsSize - 1;

    // 遍历的指针
    int t = 0;

    // 遍历数组
    while (t <= j) {
        // 当遇到红色时和红色指针交换，并将红色指针移向下一位
        if (nums[t] == 0) {
            nums[t] = nums[i];
            nums[i] = 0;
            i++;
            t++;
            continue;
        }

        if (nums[t] == 1) {
            t++;
            continue;
        }

        // 当遇到蓝色时和蓝色指针交换，并将蓝色指针移向上一位
        if (nums[t] == 2) {
            nums[t] = nums[j];
            nums[j] = 2;
            j--;
            continue;
        }
    }

}


