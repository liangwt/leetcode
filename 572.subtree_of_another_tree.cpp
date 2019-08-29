/**
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 *
 * Example 1:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return true, because t has the same structure and node values with a subtree of s.
 * Example 2:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *     /
 *    0
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return false.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 *  如何判断两棵树相同
 *
 *  从根开始判断，然后递归的判断左子树，右子树，如果左右子树也相同则两个树是相同的
 *
 *  如果判断是否为子树
 *
 *  递归的从根节点逐个于子树进行对比，判断是否相等
 *
 */

#include "include/tree.hpp"

#include <assert.h>

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        }

        if (!s || !t) {
            return false;
        }

        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isEqual(TreeNode *s, TreeNode *t) {

        if (!t && !s) {
            return true;
        }

        if (t && s) {
            if (s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // s1 t1
    auto s1 = TreeNode(3);

    auto s1_left = TreeNode(4);
    auto s1_right = TreeNode(5);
    s1.left = &s1_left;
    s1.right = &s1_right;

    auto s1_left_left = TreeNode(1);
    auto s1_left_right = TreeNode(2);
    s1_left.right = &s1_left_right;
    s1_left.left = &s1_left_left;

    auto t1 = TreeNode(4);

    auto t1_left = TreeNode(1);
    auto t1_right = TreeNode(2);
    t1.left = &t1_left;
    t1.right = &t1_right;

    // s2 t2
    auto s2 = TreeNode(3);

    auto s2_left = TreeNode(4);
    auto s2_right = TreeNode(5);
    s2.left = &s2_left;
    s2.right = &s2_right;

    auto s2_left_left = TreeNode(1);
    auto s2_left_right = TreeNode(2);
    s2_left.right = &s2_left_right;
    s2_left.left = &s2_left_left;

    auto s2_left_right_left = TreeNode(0);
    s2_left_right.left = &s2_left_right_left;

    auto t2 = TreeNode(4);

    auto t2_left = TreeNode(1);
    auto t2_right = TreeNode(2);
    t2.left = &t2_left;
    t2.right = &t2_right;

    Solution s;

    assert(s.isSubtree(&s1, &t1));
    assert(!s.isSubtree(&s2, &t2));

    return 0;
}