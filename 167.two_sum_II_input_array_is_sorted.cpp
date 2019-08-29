/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 *
 * Note:
 *
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * Example:
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */

/**
 * 使用两个指针分别指向首位，当两指针指向当值的和大于目标值时，右指针前移；和小于目标值时，左指针后移
 *
 * 这道题返回值不是zero-based的，所以返回值得加一
 */

#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = int(numbers.size() - 1), t;

        while (left < right) {
            t = numbers[left] + numbers[right];

            if (t == target) {
                return {left + 1, right + 1};
            } else if (t > target) {
                right--;
            } else {
                left++;
            }
        }

        return {};
    }
};

int main() {
    Solution s;

    vector<int> n1 = {2, 7, 11, 15};
    assert(s.twoSum(n1, 9) == vector<int>({1, 2}));

    return 0;
}