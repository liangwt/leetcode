#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    static vector<int> serialize(TreeNode *root);

    static TreeNode *deserialize(const vector<int> &arr);

    ~TreeNode() {
        delete left;
        delete right;
    }
};

vector<int> TreeNode::serialize(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }

    string r;
    queue<TreeNode *> q;
    q.push(root);
    vector<int> result;

    TreeNode *t = nullptr;

    while (!q.empty()) {
        t = q.front();
        q.pop();

        if (t) {
            q.push(t->left);
            q.push(t->right);
            result.push_back(t->val);
        } else {
            result.push_back(INT_MAX);
        }
    }

    return result;
}

TreeNode *TreeNode::deserialize(const vector<int> &arr) {
    queue<TreeNode *> q;
    int i = 1;
    TreeNode *root;

    if (!arr.empty() && arr[0] != INT_MAX) {
        root = new TreeNode(arr[0]);
        q.push(root);
    } else {
        root = nullptr;
    }

    while (!q.empty()) {
        TreeNode *p = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != INT_MAX) {
            auto *n1 = new TreeNode(arr[i]);
            p->left = n1;
            q.push(n1);
        }

        i += 1;

        if (i < arr.size() && arr[i] != INT_MAX) {
            auto *n2 = new TreeNode(arr[i]);
            p->right = n2;
            q.push(n2);
        }
        i += 1;
    }

    return root;
}