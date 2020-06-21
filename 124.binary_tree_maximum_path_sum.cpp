#include "include/header/tree.hpp"

using namespace std;

class Solution
{
private:
    int ans = INT_MIN;

public:
    int maxPathSum(TreeNode *root)
    {
        helper(root);
        return ans;
    }

    int helper(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }

        int l = helper(node->left);
        int r = helper(node->right);

        // 只选择一条路径，所以父节点可以引用
        int t1 = max(max(node->val + r, node->val + l), node->val);

        // 选择两条路径，所以父节点不能引用
        int t2 = node->val + l + r;

        ans = max(max(ans, t1), t2);

        return t1;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {1, 2, 3};
    assert(s.maxPathSum(TreeNode::deserialize(a1)) == 6);

    vector<int> a2 = {-10, 9, 20, INT_MAX, INT_MAX, 15, 7};
    assert(s.maxPathSum(TreeNode::deserialize(a2)) == 42);

    vector<int> a3 = {5, 4, 8, 11, INT_MAX, 13, 4, 7, 2, INT_MAX, INT_MAX, INT_MAX, 1};
    assert(s.maxPathSum(TreeNode::deserialize(a3)) == 48);
}