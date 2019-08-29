/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

/**
 *  首先进行排序，之后按照顺序固定一个值，在剩余的数组里选择相加等于0-nums[fixed]的值
 *
 *  在剩余数组头尾各设置一个指针，通过计算两指针的和来前后移动两指针
 *
 *  在遍历和移动指针的过程中，需要做一些操作来剪枝和去重
 *
 *  1. 当nums[fixed]大于零之后，因为是排过序的所以后面的数都是大于零的了，不可能出现满足三数相加等于零的可能了
 *  2. 当nums[fixed]的下一个数还是同一个值的话，就直接把fixed往下移动了，不然就会出现重复的结果了
 *  3. 当寻找到nums[fixed]+nums[left]+nums[right]==0时，如果left，right的指针下一个值和当前值是一样的，则继续往前往后移动，不然也会出现重复结果了
 *
 */

#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int left, t, right;
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            left = i + 1;
            right = (int) nums.size() - 1;

            while (left < right) {

                t = nums[i] + nums[left] + nums[right];

                if (t == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                } else if (t > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {-1, 0, 1, 2, -1, -4};

    assert(s.threeSum(n1) == vector<vector<int>>({{-1, 0,  1},
                                                  {-1, -1, 2}}));
    return 0;
}
