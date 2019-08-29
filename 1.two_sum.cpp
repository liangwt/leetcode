/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

/**
 * 对于数组中的一个值nums[i]和target，只要判断target - nums[i]在nums有没有就可以了
 *
 * 所以我们把nums中的值往map里写，同时查询target - nums[i]在map能不能找到
 * 只需要一遍遍历就可以
 *
 */

#include <vector>
#include <unordered_map>

#include <assert.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> _table;
        _table.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            auto idx = _table.find(target - nums[i]);

            if (idx != _table.end()) {
                return {idx->second, i};
            }

            _table[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    Solution s;

    vector<int> n1 = {2, 7, 11, 15};
    assert(s.twoSum(n1, 9) == vector<int>({0, 1}));

    return 0;
}