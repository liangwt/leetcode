#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited;
        visited.resize(nums.size());

        helper(nums, ans, temp, visited);

        return ans;
    }

    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> &visited)
    {
        if (temp.size() == nums.size())
        {
            ans.emplace_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 这个数被用了肯定不能再用了
            if (visited[i] == true)
            {
                continue;
            }

            // visited[i-1] == false 这里是关键点
            // 在递归树上，visited[i-1] == false说明两个节点位于同一层，
            // 同一层的相同元素子树是一样的，所以需要剪掉
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
            {
                continue;
            }

            visited[i] = 1;
            temp.emplace_back(nums[i]);

            helper(nums, ans, temp, visited);

            // 恢复
            temp.pop_back();
            visited[i] = 0;
        }
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 1, 2};
    vector<vector<int>> r1 = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    assert(s.permuteUnique(n1) == r1);
}