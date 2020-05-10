/**
 * 记录从根到每个节点的路径，按照此路径进行对比找出共同的父节点
 **/

#include <vector>
#include "include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    vector<TreeNode *> p_path;
    vector<TreeNode *> q_path;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path;
        getPath(root, p, q, path);

        int len_p = p_path.size();
        int len_q = q_path.size();
        int i = 0;

        while (i < len_p && i < len_q)
        {
            if (q_path[i]->val != p_path[i]->val)
            {
                break;
            }
            i++;
        }

        return q_path[i - 1];
    }

    void getPath(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> &path)
    {
        if (!root)
        {
            return;
        }

        path.push_back(root);

        if (root->val == p->val)
        {
            this->p_path = path;
        }

        if (root->val == q->val)
        {
            this->q_path = path;
        }

        if (root->left)
        {
            getPath(root->left, p, q, path);
            path.pop_back();
        }

        if (root->right)
        {
            getPath(root->right, p, q, path);
            path.pop_back();
        }

        return;
    }
};

int main()
{
    vector<int> arr1 = {3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4};
    TreeNode *root = TreeNode::deserialize(arr1);

    assert(Solution().lowestCommonAncestor(root, root->left, root->right) == root);
    assert(Solution().lowestCommonAncestor(root, root->left, root->left->right->right) == root->left);
}