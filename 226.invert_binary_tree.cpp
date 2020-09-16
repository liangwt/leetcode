#include "include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        helper(root);

        return root;
    }

    void helper(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        auto t = root->left;
        root->left = root->right;
        root->right = t;

        if (root->left)
        {
            helper(root->left);
        }

        if (root->right)
        {
            helper(root->right);
        }

        return;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {4, 2, 7, 1, 3, 6, 9};
    auto root = TreeNode::deserialize(a1);

    vector<int> r1 = {4, 7, 2, 9, 6, 3, 1};
    auto invert = TreeNode::deserialize(r1);

    assert(TreeNode::equal(s.invertTree(root), invert));
}