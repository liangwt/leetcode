#include "include/header/tree.hpp"

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }

        int mid = (begin + end) / 2;

        auto root = new TreeNode(nums[mid]);

        root->left = helper(nums, begin, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {-10, -3, 0, 5, 9};
    assert(TreeNode::serialize(s.sortedArrayToBST(n1)) == vector<int>({0, -10, 5, INT_MAX, -3, INT_MAX, 9, INT_MAX, INT_MAX, INT_MAX, INT_MAX}));
}