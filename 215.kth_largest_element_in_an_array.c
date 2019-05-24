/**
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * Example 2:
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
**/
#include <stdio.h>

int findKthLargest(int *nums, int numsSize, int k);

int partition(int *nums, int start, int stop);

int main() {
    int nums[] = {3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6}, k = 20;
    int r = findKthLargest(nums, sizeof(nums) / sizeof(int), k);
    printf("ans: %d\n", r);
}

/**
 * 思路1：
 * 可以使用数组从大到小排序，第k-1即为第k大的元素
 * 此时时间复杂度由排序算法决定，大部分排序算法平均复杂度O(nlogn)，空间复杂度O(1)
 *
 * 思路2：
 * 使用优先队列，使用最小堆，当堆数量超过k时移除堆顶元素。遍历完成后堆顶元素就是第k大
 * 此时时间复杂度等于建堆*元素个数即 O(nlogk)，空间复杂度O(k)
 *
 * 思路3：
 * 和快速排序的思想一样，
 * 1. 先选取任意一个中间值，对于比中间值大的数字放左边，比中间值小的数字放右边
 *    1.1 可以在数组两端分别设置指针left、right，两指针向中间遍历。
 *    1.2 先从左往右找到一个比中间值小的，再从右往左找一个比中间值大的，交换两者。
 *    1.3 最后在两指针相遇的地方放入中间值 X（此处错误)
 *    1.3 正确的做法是直到left、超过right，此时right指向的是最大值区域的最后一个，将中间值放入right所在位置
 *
 *  任意值
 *    |
 *    3  2,  1,  5,  6,  4
 *       ^      交换     ^
 *      left   <==>    right
 *
 *  任意值
 *    |
 *    3  4,  1,  5,  6,  2
 *           ^       ^
 *         left<==>right
 *
 *  任意值
 *    |
 *    3  4,  6,  5,  1,  2
 *               ^
 *             left
 *               ^
 *             right
 *
 *
 *    3  4,  6,  5,  1,  2
 *    ^          ^   ^
 *  任意值 <==> right left
 *
 *    5  4,  6,  3,  1,  2
 *
 * 2. 在上一步中得到的中间值位置pos，在pos左边都比中间值大，在pos右边都比中间值小
 *    所以对比k与pos的大小关系，
 *    2.1 如果k-1==pos说明此位置正好是第k大的数据。
 *    2.2 如果k-1>pos说明期望的返回结果在pos右侧，和第一步一样，求右侧中间值位置来循环执行，
 *    2.3 如果k-1<pos说明期望的返回结果在左侧，再次求左侧中间值位置来循环执行
 *
 */
int findKthLargest(int *nums, int numsSize, int k) {
    int start = 0, stop = numsSize - 1, t = 0;

    while (1) {
        t = partition(nums, start, stop);

        if (t == k - 1) {
            return nums[t];
        }

        if (t > k - 1) {
            stop = t - 1;
        } else {
            start = t + 1;
        }
    }
}

int partition(int *nums, int start, int stop) {
    int left = start + 1, right = stop;
    int idx = nums[start];

    while (left <= right) {
        if (nums[right] < idx) {
            right--;
            continue;
        }

        if (nums[left] > idx) {
            left++;
            continue;
        }

        int t = nums[left];
        nums[left] = nums[right];
        nums[right] = t;
        left++;
        right--;
    }

    nums[start] = nums[right];
    nums[right] = idx;

    return right;
}