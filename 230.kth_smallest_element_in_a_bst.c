/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Example 1:
 *
 * Input: root = [3,1,4,null,2], k = 1
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * Output: 1
 * Example 2:
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * Output: 3
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

#include <stdio.h>
#include "include/tree_node.h"
#include "include/stack.h"

int kthSmallest(struct TreeNode *root, int k);

int main() {
    int s[] = {2, 0, 33, NULL_NODE, 1, 25, 40, NULL_NODE, NULL_NODE, 11, 31, 34, 45, 10, 18, 29, 32, NULL_NODE, 36, 43,
               46, 4, NULL_NODE, 12, 24, 26, 30, NULL_NODE, NULL_NODE, 35, 39, 42, 44, NULL_NODE, 48, 3, 9, NULL_NODE,
               14, 22, NULL_NODE, NULL_NODE, 27, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 38, NULL_NODE, 41,
               NULL_NODE, NULL_NODE, NULL_NODE, 47, 49, NULL_NODE, NULL_NODE, 5, NULL_NODE, 13, 15, 21, 23, NULL_NODE,
               28, 37, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 8,
               NULL_NODE, NULL_NODE, NULL_NODE, 17, 19, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE,
               NULL_NODE, NULL_NODE, 7, NULL_NODE, 16, NULL_NODE, NULL_NODE, 20, 6};

    struct TreeNode *root = tree_create_from_arr(s, sizeof(s) / sizeof(int));
    int o = kthSmallest(root, 25);
    printf("an: %d\n", o);
}

/**
 * 二叉搜索数的中序遍历结果就是从小到大的顺序
 *
 * @param root
 * @param k
 * @return
 */
int kthSmallest(struct TreeNode *root, int k) {
    stack p, *sp = &p;
    stack_init(sp);

    struct TreeNode *cur = root;

    // 当遍历到根节点时，stack有可能时空的的
    while (!stack_is_empty(sp) || cur) {
        while (cur) {
            stack_push(sp, cur);
            cur = cur->left;
        }

        cur = stack_pop(sp);
        k--;
        if (k == 0) {
            break;
        }
        cur = cur->right;
    }

    stack_destory(sp);

    return cur ? cur->val : 0;
}


