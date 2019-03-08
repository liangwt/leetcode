/**
 *  * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/tree_node.h"
#include "include/stack.h"
#include "include/queue.h"

int **zigzagLevelOrder(struct TreeNode *root, int **columnSizes, int *returnSize);

int main(int argc, char *argv[]) {
    int p[5] = {3, 9, 20, 15, 7}, num = 5;
    struct TreeNode *root = tree_create_from_arr(p, num);
    int returnSize = 0, **r, *columnSizes;

    r = zigzagLevelOrder(root, &columnSizes, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }

    free(columnSizes);
    free(r);
}

/**
 * 两个栈分别
 * 一个栈左子节点先进
 * 一个栈右子节点先进
 *
 * @param root
 * @param columnSizes
 * @param returnSize
 * @return
 */
int **zigzagLevelOrder(struct TreeNode *root, int **columnSizes, int *returnSize) {

    if(!root){
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }

    stack s1, *sp_r = &s1;
    stack s2, *sp_l = &s2;

    int level = 0;
    int *cs = malloc(sizeof(int) * 1000);
    int **r = malloc(sizeof(int *) * 1000);

    stack_init(sp_r);
    stack_init(sp_l);

    stack_push(sp_r, root);

    while (!stack_is_empty(sp_r) || !stack_is_empty(sp_l)) {

        if (!stack_is_empty(sp_r)) {
            int len = stack_length(sp_r);
            int *cr = malloc(sizeof(int) * len);

            for (int i = 0; i < len; ++i) {
                struct TreeNode *t = (struct TreeNode *) stack_pop(sp_r);
                cr[i] = t->val;
                // 左子节点先进
                if (t->left)
                    stack_push(sp_l, t->left);
                if (t->right)
                    stack_push(sp_l, t->right);
            }
            cs[level] = len;
            r[level] = cr;
            level++;
        }

        if (!stack_is_empty(sp_l)) {
            int len = stack_length(sp_l);
            int *cr = malloc(sizeof(int) * len);

            for (int i = 0; i < len; ++i) {
                struct TreeNode *t = (struct TreeNode *) stack_pop(sp_l);
                cr[i] = t->val;
                // 右子节点先进
                if (t->right)
                    stack_push(sp_r, t->right);
                if (t->left)
                    stack_push(sp_r, t->left);
            }
            cs[level] = len;
            r[level] = cr;
            level++;
        }

    }

    *columnSizes = cs;
    *returnSize = level;
    return r;

}














