/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int total = 0;

        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
        {
            total += root->left->val;
        }

        total += sumOfLeftLeaves(root->left);
        total += sumOfLeftLeaves(root->right);

        return total;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    assert(s.sumOfLeftLeaves(TreeNode::deserialize(arr)) == 24);
}