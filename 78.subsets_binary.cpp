/*
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */

/**
 * 对于长度为n的数组，每个数字都有出现和不出现的两种选择，总共2^n种。把2^n用二进制表示，则从0-2^n的每一个数字取位置为1的构成子集
 *
 * 例如 [1, 2, 3]
 *
 *           [1, 2, 3]
 * 0=>0000   []
 * 1=>0001   [3]
 * 2=>0010   [2]
 * 3=>0011   [1, 2]
 * 4=>0100   [1]
 * 5=>0101   [1, 3]
 * 6=>0110   [1, 2]
 * 7=>0111   [1, 2, 3]
 *
 */

#include <unordered_set>
#include <vector>

#include "include/header/utils.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        long len = nums.size();
        vector<vector<int>> result;

        for (long i = 0; i < pow(2, len); i++)
        {
            vector<int> t = {};
            for (long j = 0; j < len; j++)
            {
                if (i & (1 << j))
                {
                    t.push_back(nums[j]);
                }
            }

            result.push_back(t);
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 3, 2};
    vector<vector<int>> r1 = {
        {},
        {3},
        {1},
        {2},
        {1, 2, 3},
        {1, 3},
        {2, 3},
        {1, 2},
    };

    assert(vector_equal(s.subsets(n1), r1));

    vector<int> n2 = {2, 4, 3, 5};
    vector<vector<int>> r2 = {
        {},
        {2},
        {3},
        {4},
        {5},
        {2, 3},
        {2, 4},
        {2, 5},
        {3, 4},
        {3, 5},
        {4, 5},
        {2, 3, 4},
        {2, 3, 5},
        {3, 4, 5},
        {2, 3, 4, 5},
    };
    assert(vector_equal(s.subsets(n1), r1));

    return 0;
}