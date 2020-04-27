/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // mid右侧一定是有序递增的
            if (nums[mid] < nums[r]) {
                // target 在mid右侧
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                }
                    // target 在mid左侧
                else {
                    r = mid - 1;
                }
            }
                // mid左侧一定是有序递增的
            else {
                // target 在mid左侧
                if (nums[mid] > target && nums[l] <= target) {
                    r = mid - 1;
                }
                    // target 在mid右侧
                else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {4, 5, 6, 7, 0, 1, 2};
    assert(s.search(n1, 0) == 4);

    vector<int> n2 = {4, 5, 6, 7, 0, 1, 2};
    assert(s.search(n2, 3) == -1);

    vector<int> n3 = {};
    assert(s.search(n3, 3) == -1);

}