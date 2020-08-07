#include "./include/header/tree.hpp"

using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (p && q && p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<int> p1 = {1, 2, 3};
    vector<int> q1 = {1, 2, 3};

    assert(s.isSameTree(TreeNode::deserialize(p1), TreeNode::deserialize(q1)) == true);

    vector<int> p2 = {1, 2};
    vector<int> q2 = {1, INT_MAX, 2};

    assert(s.isSameTree(TreeNode::deserialize(p2), TreeNode::deserialize(q2)) == false);

    vector<int> p3 = {1, 2, 1};
    vector<int> q3 = {1, 1, 2};

    assert(s.isSameTree(TreeNode::deserialize(p3), TreeNode::deserialize(q3)) == false);

    return 0;
}