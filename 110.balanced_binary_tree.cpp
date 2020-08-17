#include "include/header/tree.hpp"

using namespace std;

class Solution
{
private:
    bool result = true;

public:
    bool isBalanced(TreeNode *root)
    {
        helper(root);
        return this->result;
    }

    int helper(TreeNode *root)
    {
        if (!result)
        {
            return -1;
        }

        if (!root)
        {
            return 0;
        }

        int l = 0, r = 0;

        if (root->left)
        {
            l = helper(root->left);
        }

        if (root->right)
        {
            r = helper(root->right);
        }

        if (abs(r - l) > 1)
        {
            this->result = false;
        }

        return max(r, l) + 1;
    }
};

int main()
{
    Solution s;

    vector<int> v1 = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    auto t1 = TreeNode::deserialize(v1);
    assert(s.isBalanced(t1) == true);

    vector<int> v2 = {1, 2, 2, 3, 3, INT_MAX, INT_MAX, 4, 4};
    auto t2 = TreeNode::deserialize(v2);
    assert(s.isBalanced(t2) == false);
}