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
 * 回溯法
 * 从第一个数字到最后一个构成了一棵树
 *
 *                         []
 *                   /      |    \
 *                 /        |     \
 *               /          |      \
 *             [1]         [2]    [3]
 *           /    \         /     
 *          /      \       /       
 *       [1,2]    [1,3] [2,3]      
 *      /                
 *   [1,2,3]              
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
        vector<int> temp;
        vector<vector<int>> ans;

        helper(nums, -1, temp, ans);

        return ans;
    }

    void helper(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &ans)
    {
        ans.emplace_back(temp);

        for (int i = idx + 1; i < nums.size(); i++)
        {
            temp.emplace_back(nums[i]);
            helper(nums, i, temp, ans);
            temp.pop_back();
        }

        return;
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