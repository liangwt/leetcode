#include "include/header/tree.hpp"
#include <iostream>

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }

        int val = preorder[0];
        TreeNode *root = new TreeNode(val);

        auto i = inorder.begin();
        while (i != inorder.end())
        {
            if (*i == val)
            {
                break;
            }
            i++;
        }
        
        auto ii = vector<int>(inorder.begin(), i);
        auto pp = vector<int>(preorder.begin() + 1, preorder.begin() + ii.size() + 1);
        TreeNode *left = buildTree(pp, ii);
        root->left = left;

        auto jj = vector<int>(i + 1, inorder.end());
        auto rr = vector<int>(preorder.end() - jj.size(), preorder.end());
        TreeNode *right = buildTree(rr, jj);
        root->right = right;

        return root;
    }
};

int main()
{
    Solution s;

    vector<int> p1 = {3, 9, 20, 15, 7};
    vector<int> i1 = {9, 3, 15, 20, 7};

    assert(TreeNode::serialize(s.buildTree(p1, i1)) == vector<int>({3, 9, 20, INT_MAX, INT_MAX, 15, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX}));
}
