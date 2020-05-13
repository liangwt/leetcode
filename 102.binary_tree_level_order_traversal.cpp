#include <vector>
#include "include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> t;

            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                q.pop();

                t.push_back(n->val);

                if (n->left)
                {
                    q.push(n->left);
                }

                if (n->right)
                {
                    q.push(n->right);
                }
            }
            ans.push_back(t);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    auto root = TreeNode::deserialize(arr);
    vector<vector<int>> ans = {
        {3},
        {9, 20},
        {15, 7}};

    assert(s.levelOrder(root) == ans);
}