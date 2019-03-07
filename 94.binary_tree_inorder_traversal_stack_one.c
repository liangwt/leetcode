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
#include "include/tree_node.h"
#include "include/stack.h"

int *inorderTraversal(struct TreeNode *root, int *returnSize);

int main(int argc, char *argv[]) {
    int p[4] = {1, NULL_NODE, 2, 3}, num = 4;
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
    stack s;
    stack *sp = &s;

    stack_init(&s);

    struct TreeNode *top;
    struct TreeNode *c_node = root;

    while (c_node || !stack_is_empty(sp)) {

        while (c_node) {
            stack_push(sp, c_node);
            c_node = c_node->left;
        }

        top = stack_pop(sp);
        r[*returnSize] = top->val;
        (*returnSize)++;

        if (top->right) {
            c_node = top->right;
        }
    }

    return r;
}










