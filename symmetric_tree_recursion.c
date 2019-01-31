#include <stdbool.h>

bool _isSymmetric(struct TreeNode *left, struct TreeNode *right);

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode *root)
{
    if (!root)
        return true;

    return _isSymmetric(root->left, root->right);
}

bool _isSymmetric(struct TreeNode *left, struct TreeNode *right)
{
    if (!left && !right)
        return true;
        
    if (left && right && left->val == right->val)
        return _isSymmetric(left->left, right->right) 
            && _isSymmetric(left->right, right->left);

    return false;
}
