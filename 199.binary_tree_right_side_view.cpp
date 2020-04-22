#include <vector>
#include <queue>
#include "include/header/tree.hpp"

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<int> ans;

        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            ans.push_back(q.back()->val);

            while (len-- > 0)
            {
                auto node = q.front();q.pop();
                
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {1, 2, 3, INT_MAX, 5, INT_MAX, 4, 6};
    assert(s.rightSideView(TreeNode::deserialize(a1)) == vector<int>({1, 3, 4, 6}));
}