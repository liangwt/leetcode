#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool _isValidBST(struct TreeNode *node, long min, long max);

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
bool isValidBST(struct TreeNode *root)
{
    if (!root)
        return true;

    return _isValidBST(root, LONG_MIN, LONG_MAX);
}

bool _isValidBST(struct TreeNode *node, long min, long max)
{
    if (!node)
        return true;

    if (node->val < min || node->val > max)
        return false;

    return _isValidBST(node->left, min, node->val) && _isValidBST(node->right, node->val, max);
}