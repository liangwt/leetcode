/**
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * Note:
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */

#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        if (nums.empty()) {
            return -1;
        }

        int left = 0, right = 0, sum = nums[0];
        int len = (int) nums.size();

        while (left <= right && right < len) {
            if (sum == k) {
                return right - left + 1;
            }

            if (sum < k) {
                sum += nums[++right];
            } else {
                sum = sum - nums[left++];
            }
        }

        return -1;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {1, 1, 1};
    assert(s.subarraySum(n1, 2) == 2);

    vector<int> n2 = {1, 2, 3, 4, 5};
    assert(s.subarraySum(n2, 9) == 3);

    vector<int> n3 = {};
    assert(s.subarraySum(n3, 9) == -1);

    vector<int> n4 = {5};
    assert(s.subarraySum(n4, 5) == 1);

    vector<int> n5 = {-1, -1, 1};
    assert(s.subarraySum(n5, 0) == 1);

    return 0;
}