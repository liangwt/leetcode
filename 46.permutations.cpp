#include <vector>
#include <unordered_set>
#include "include/header/utils.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited;

        visited.resize(nums.size());
        helper(nums, ans, temp, visited);

        return ans;
    }

    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> visited)
    {
        if (temp.size() == nums.size())
        {
            ans.emplace_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }

            visited[i] = 1;
            temp.emplace_back(nums[i]);

            helper(nums, ans, temp, visited);

            visited[i] = 0;
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