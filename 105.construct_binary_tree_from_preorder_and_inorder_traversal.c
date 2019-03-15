/**
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 */

#include <stdio.h>
#include "include/tree_node.h"

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize);

struct TreeNode *
_buildTree(int *preorder, int preorderStart, int preorderEnd, int *inorder, int inorderStart, int inorderEnd);

/**
 *
 *           1
 *        2     3
 *      4  5  6  7
 *    8
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    int preorder[8] = {1, 2, 4, 8, 5, 3, 6, 7};
    int inorder[8] = {8, 4, 2, 5, 1, 6, 3, 7};

    struct TreeNode *root = buildTree(preorder, 8, inorder, 8);
}

/**
 *
 * 1. 先序遍历(preorder)的第一个元素(preorderStart)肯定是根节点
 * 2. 在中序遍历(inorder)中找到根节点位置 idx， idx左边[inorderStart, idx-1]的都是左子树元素，idx右边[idx+1, inorderEnd]都是右子树元素
 * 3. 同时在先序遍历(preorder)中：
 *    1. preorderStart往后数左子树长度(idx-inorderStart)均为左子树,即[preorderStart+1, preorderStart+idx-inorderStart]
 *    2. preorderEnd往前数右子树的长度(inorderEnd-idx)都为右子树元素,
 *       或者从最后一个左子树元素往后到结束，即[preorderStart+idx-inorderStart+1, preorderEnd]
 * 4. 所以从i处形成递归
 *
 * @param preorder
 * @param preorderSize
 * @param inorder
 * @param inorderSize
 * @return
 */
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    struct TreeNode *root = _buildTree(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);

    return root;
}

struct TreeNode *
_buildTree(int *preorder, int preorderStart, int preorderEnd, int *inorder, int inorderStart, int inorderEnd) {

    if (preorderStart > preorderEnd || inorderStart > inorderEnd) {
        return NULL;
    }

    int idx;

    // 先序遍历(preoider)的第一个元素肯定是根节点
    struct TreeNode *root = tree_create_node(preorder[preorderStart]);

    // 在中序遍历(inorder)中找到根节点位置 i， i左边的都是左子树元素，i右边都是右子树元素
    for (idx = inorderStart; idx < inorderEnd; idx++) {
        if (root->val == inorder[idx]) {
            break;
        }
    }

    // 先序遍历(preoider)中i(包含i)的左侧均为左子树，且第二个元素是根节点的左孩子
    root->left =
        _buildTree(preorder, preorderStart + 1, preorderStart + idx - inorderStart, inorder, inorderStart,
                   idx - 1);

    // 先序遍历(preoider)中i的右侧均为右子树，且右侧第一个元素是根节点的左孩子
    root->right =
        _buildTree(preorder, preorderStart + idx - inorderStart + 1, preorderEnd, inorder, idx + 1,
                   inorderEnd);

    return root;
}






















