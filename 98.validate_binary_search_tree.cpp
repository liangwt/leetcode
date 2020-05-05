#include <vector>
#include "include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        vector<int> val;
        bool ans = true;
        helper(root, val, ans);

        return ans;
    }

    void helper(TreeNode *root, vector<int> &val, bool &ans)
    {
        if (!ans)
        {
            return;
        }

        if (root->left)
        {
            helper(root->left, val, ans);
        }

        if (val.empty())
        {
            val.push_back(root->val);
        }
        else
        {
            if (val[0] < root->val)
            {
                val[0] = root->val;
            }
            else
            {
                ans = false;
            }
        }

        if (root->right)
        {
            helper(root->right, val, ans);
        }

        return;
    }
};

int main()
{
    Solution s;
    vector<int> a1 = {5, 1, 4, INT_MAX, INT_MAX, 3, 6};
    TreeNode *r1 = TreeNode::deserialize(a1);
    assert(!s.isValidBST(r1));

    vector<int> a2 = {2, 1, 3};
    TreeNode *r2 = TreeNode::deserialize(a2);
    assert(s.isValidBST(r2));
}