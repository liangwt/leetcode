#include <vector>
#include <unordered_set>
#include "include/header/utils.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> result;
        _helper(nums_set, temp, result);
        return result;
    }

    void _helper(unordered_set<int> nums_set, vector<int> &temp, vector<vector<int>> &result)
    {
        if (nums_set.empty())
        {
            result.push_back(temp);
            return;
        }

        for (const auto &num : nums_set)
        {
            temp.push_back(num);

            unordered_set<int> n_set = nums_set;
            n_set.erase(num);
            _helper(n_set, temp, result);
            temp.pop_back();
        }

        return;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}};

    assert(vector_equal(s.permute(nums), ans));
}