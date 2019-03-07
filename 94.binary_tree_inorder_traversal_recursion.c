/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * Output: [1,3,2]
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "include/tree_node.h"
#include "include/queue.h"

int *inorderTraversal(struct TreeNode *root, int *returnSize);

void _inorderTraversal(struct TreeNode *root, int *returnSize, int *r);

int main(int argc, char *argv[]) {
    int p[6] = {1, NULL_NODE, 2, 3}, num = 4;
    struct TreeNode *root = tree_create_from_arr(p, num);
    int returnSize = 0, *r;

    r = inorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", r[i]);
    }

    free(r);
}

/**
 * 中序遍历
 *
 * @param root
 * @param returnSize
 * @return
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *r = malloc(sizeof(int) * 10000);
    *returnSize = 0;

    _inorderTraversal(root, returnSize, r);

    return r;
}

void _inorderTraversal(struct TreeNode *node, int *returnSize, int *r) {
    if (!node)
        return;

    if (node->left)
        _inorderTraversal(node->left, returnSize, r);

    r[*returnSize] = node->val;
    (*returnSize)++;

    if (node->right)
        _inorderTraversal(node->right, returnSize, r);

}









