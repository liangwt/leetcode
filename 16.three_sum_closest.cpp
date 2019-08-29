/**
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

/**
 * 思路和 three_sum 一样，固定一个值，然后用两个指针前后移动
 * 在指针移动的过程中，同时更新与目标值的最小差值，进而更新三个数的和
 */

#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int left, right, t, c, closest = INT_MAX, ret = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            left = i + 1, right = (int) nums.size() - 1;

            while (left < right) {
                t = nums[i] + nums[left] + nums[right];
                c = abs(t - target);

                if (c < closest) {
                    ret = t;
                    closest = c;
                }

                if (t == target) {
                    return ret;
                } else if (t > target) {
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

    vector<int> n1 = {-1, 2, 1, -4};

    assert(s.threeSumClosest(n1, 1) == 2);

    return 0;
}