/**
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }

        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;

        while (left < right)
        {
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                break;
            }

            mid = (left + right) / 2;
        }

        if (nums[mid] == target)
        {
            int min = mid, max = mid;
            for (; min >= 0; min--)
            {
                if (nums[min] != target)
                {
                    break;
                }
            }

            for (; max <= nums.size() - 1; max++)
            {
                if (nums[max] != target)
                {
                    break;
                }
            }

            return {min + 1, max - 1};
        }
        else
        {
            return {-1, -1};
        }
    }
};

int main()
{
    Solution s;
    auto nums = vector<int>{1, 4};
    int target = 4;
    auto result = s.searchRange(nums, target);

    cout << result[0] << ", " << result[1];
}