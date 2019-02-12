/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

#include <stdlib.h>
#include "include/queue.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int **columnSizes, int *returnSize)
{
    int **r = malloc(sizeof(int *) * 1000);
    *columnSizes = malloc(sizeof(int) * 1000);

    if (!root)
    {
        *returnSize = 0;
        *columnSizes[0] = 0;
        return r;
    }

    int level = 0;
    int *t;

    struct TreeNode *tree_node;

    queue q;
    queue *qp = &q;
    queue_node *n;

    queue_init(qp);
    queue_push(qp, root);

    while (!queue_is_empty(qp))
    {
        int l = queue_length(qp);
        (*columnSizes)[level] = l;
        t = malloc(sizeof(int) * l);
        r[level] = t;

        for (int i = 0; i < l; i++)
        {
            n = queue_pop(qp);
            tree_node = (struct TreeNode *)n->val;
            r[level][i] = tree_node->val;

            if (tree_node->left)
            {
                queue_push(qp, tree_node->left);
            }
            if (tree_node->right)
            {
                queue_push(qp, tree_node->right);
            }
        }
        level++;
    }

    queue_destory(qp);

    *returnSize = level;

    return r;
}