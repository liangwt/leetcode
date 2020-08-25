#include <vector>
#include <unordered_set>
#include "include/header/utils.hpp"

using namespace std;

struct VectorHash
{
    size_t operator()(const std::vector<int> &v) const
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
        {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution
{
private:
    unordered_set<vector<int>, VectorHash> st;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        st = {};

        vector<int> temp;
        helper(nums, -1, temp);

        vector<vector<int>> ans;
        for (auto n = st.begin(); n != st.end(); n++)
        {
            ans.push_back(*n);
        }
        return ans;
    }

    void helper(vector<int> &nums, int idx, vector<int> &temp)
    {
        for (int i = idx + 1; i < nums.size(); i++)
        {
            if (idx >= 0 && nums[i] < nums[idx])
            {
                continue;
            }

            temp.push_back(nums[i]);
            if (temp.size() >= 2)
            {
                st.insert(temp);
            }

            helper(nums, i, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {4, 6, 7, 7};
    assert(vector_equal(s.findSubsequences(n1), vector<vector<int>>({{4, 6}, {4, 7}, {4, 6, 7}, {4, 6, 7, 7}, {6, 7}, {6, 7, 7}, {7, 7}, {4, 7, 7}})));

    vector<int> n2 = {4, 3, 2, 1};
    assert(s.findSubsequences(n2).empty() == true);
}