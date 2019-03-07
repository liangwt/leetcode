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

    struct TreeNode *cur = root;
    struct TreeNode *pre;

    while (cur) {
        // 如果cur没有左节点，直接输出cur并把cur移动到右节点
        if (!cur->left) {
            r[*returnSize] = cur->val;
            (*returnSize)++;
            cur = cur->right;
            continue;
        }

        // 如果cur有左节点，在左子树中寻找cur在中序遍历的前继节点pre
        pre = cur->left;
        while (pre->right && pre->right != cur) {
            pre = pre->right;
        }

        if (pre->right) {
            // 如果pre的右孩子已经有指向了，说明是回溯到此的，此时cur的左子数已经输出完了
            // 所以输出cur，并将cur指向cur的右孩子，然后将pre的右孩子恢复到NULL
            r[*returnSize] = cur->val;
            (*returnSize)++;
            cur = cur->right;
            pre->right = NULL;
        } else {
            // 如果右孩子还没有指向过，就把pre的右孩子指向cur
            // 移动cur到cur的左孩子
            // 此过程在构建线索树
            pre->right = cur;
            cur = cur->left;
        }
    }

    return r;
}










