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

/**
 * 使用两个指针，一个指向开头红色的(0)，一个指向蓝色的(2)
 * 然后遍历数组，当遇到红色时和红色指针交换，并将红色指针移向下一位
 *
 * 当交换红色指针时，因为之前的部分都已经扫描过了，所以不是0，就是1，
 * 在交换完红色之后，即使交换过来，也是已知的，所以当前位置也需要往后移动一位
 *
 * 当遇到蓝色时和蓝色指针交换，并将蓝色指针移向上一位
 *
 */

#include <vector>

#include <assert.h>

using namespace std;


class Solution {
public:
    void sortColors(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, idx = left;

        while (left < right && idx <= right) {
            if (nums[left] == 0) {
                left++;
                continue;
            }
            if (nums[right] == 2) {
                right--;
                continue;
            }

            if (idx < left) {
                idx++;
                continue;
            }

            switch (nums[idx]) {
                case 0:
                    swap(nums[idx], nums[left]);
                    break;
                case 1:
                    idx++;
                    break;
                case 2:
                    swap(nums[idx], nums[right]);
                    break;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> n1 = {2, 0, 2, 1, 1, 0};
    s.sortColors(n1);
    assert(n1 == vector<int>({0, 0, 1, 1, 2, 2}));

    vector<int> n2 = {};
    s.sortColors(n2);
    assert(n2 == vector<int>({}));

    vector<int> n3 = {1, 2, 0, 1, 2, 0, 1};
    s.sortColors(n3);
    assert(n3 == vector<int>({0, 0, 1, 1, 1, 2, 2}));
}



