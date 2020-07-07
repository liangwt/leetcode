#include "include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        try
        {
            helper(root, 0, sum);
            return false;
        }
        catch (bool e)
        {
            return true;
        }
    }

    void helper(TreeNode *root, int up, int target)
    {
        if (!root)
        {
            return;
        }

        if (!root->right && !root->left)
        {
            if (up + root->val == target)
            {
                throw true;
            }
            return;
        }

        if (root->left)
        {
            helper(root->left, up + root->val, target);
        }

        if (root->right)
        {
            helper(root->right, up + root->val, target);
        }
    }
};

int main()
{
    Solution s;
    vector<int> a1 = {5, 4, 8, 11, INT_MAX, 13, 4, 7, 2, INT_MAX, INT_MAX, INT_MAX, 1};
    auto root = TreeNode::deserialize(a1);
    assert(s.hasPathSum(root, 22) == true);
}