#include <stdlib.h>
#include "./include/utils.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *_sortedArrayToBST(int *nums, int start, int end);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    return _sortedArrayToBST(nums, 0, numsSize - 1);
}
struct TreeNode *_sortedArrayToBST(int *nums, int start, int end)
{
    int i;
    if(start > end){
        return NULL;
    }
    if (start == end)
    {
        i = start;
    }
    else
    {
        i = (end - start) / 2 + start;
    }

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[i];
    node->left = _sortedArrayToBST(nums, start, i - 1);
    node->right = _sortedArrayToBST(nums, i + 1, end);

    return node;
}