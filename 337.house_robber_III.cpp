/**
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [3,2,3,null,3,null,1]
 *
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 *
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *
 * Input: [3,4,5,1,3,null,1]
 *
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 *
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

/**
 * 对于某个根节点如果选择了此节点，那么就不能再选择它的左右子节点了，所以只能选择左右子节点的左右子节点。
 * 这时的一个可能值就是 root->val + dp[root->left->left] + dp[root->left->right] + dp[root->right->left] + dp[root->right->right]
 *
 * 对于某个根节点来说也可以不选择本身的节点，而是选择左右子节点
 * 此时的值为 dp[root->left] + dp[root->right]
 *
 * 取以上两者比较大的值即可
 *
 */

#include "include/header/tree.hpp"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rob(TreeNode *root) {
        unordered_map<TreeNode *, int> _table;

        return _helper(root, _table);
    }

    int _helper(TreeNode *node, unordered_map<TreeNode *, int> &_table) {
        if (node == nullptr) {
            return 0;
        }

        if (_table.count(node)) {
            return _table[node];
        }

        int val = 0;

        // 不包含左节点的值
        if (node->left) {
            val += _helper(node->left->left, _table) + _helper(node->left->right, _table);
        }

        // 不包含右节点的值
        if (node->right) {
            val += _helper(node->right->left, _table) + _helper(node->right->right, _table);
        }

        // 左右节点的和
        int t = _helper(node->left, _table) + _helper(node->right, _table);

        // 返回包含当前节点+不包含左右节点的值、包含左右节点的值中的最大值
        int result = max(t, val + node->val);

        _table[node] = result;

        return result;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {3, 2, 3, INT_MAX, 3, INT_MAX, 1};
    auto r1 = TreeNode::deserialize(n1);
    assert(s.rob(r1) == 7);

    vector<int> n2 = {3, 4, 5, 1, 3, INT_MAX, 1};
    auto r2 = TreeNode::deserialize(n2);
    assert(s.rob(r2) == 9);

    return 0;
}