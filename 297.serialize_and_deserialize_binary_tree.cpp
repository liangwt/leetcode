/**
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * You may serialize the following tree:
 * 
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */

/**
 * 对于序列化程序来说，使用队列进行层序遍历
 * 
 * 对于反序列化程序来说，依旧使用队列把数组中的元素拼接到树中
 */

#include "include/header/tree.hpp"
#include <string>
#include <queue>
#include <iostream>

using namespace std;

vector<string> explode(string str, string d)
{
    string t = "";
    vector<string> vect;
    for (auto s : str)
    {
        if (s == ' ')
        {
            vect.push_back(t);
            t = "";
        }
        else
        {
            t += s;
        }
    }

    if (t != "")
    {
        vect.push_back(t);
    }

    return vect;
}

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }

        string r;
        queue<TreeNode *> q;
        q.push(root);

        TreeNode *t = NULL;

        while (!q.empty())
        {
            t = q.front();
            q.pop();

            if (t)
            {
                q.push(t->left);
                q.push(t->right);
                r = r + to_string(t->val) + " ";
            }
            else
            {
                r += "NULL ";
            }
        }

        return r.erase(r.find_last_not_of("NULL ") + 1);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> arr = explode(data, " ");

        queue<TreeNode *> q;
        int i = 1;
        TreeNode *root;

        if (arr.size() > 0 && arr[0] != "NULL")
        {
            root = new TreeNode(stoi(arr[0]));
            q.push(root);
        }
        else
        {
            root = nullptr;
        }

        while (!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();

            if (i < arr.size() && arr[i] != "NULL")
            {
                cout << arr[i] << endl;
                TreeNode *n1 = new TreeNode(stoi(arr[i]));
                p->left = n1;
                q.push(n1);
            }

            i += 1;

            if (i < arr.size() && arr[i] != "NULL")
            {
                cout << arr[i] << endl;
                TreeNode *n2 = new TreeNode(stoi(arr[i]));
                p->right = n2;
                q.push(n2);
            }
            i += 1;
        }

        return root;
    }
};

int main()
{
    TreeNode root = TreeNode(1);
    TreeNode n1 = TreeNode(2);
    TreeNode n2 = TreeNode(3);
    TreeNode n3 = TreeNode(4);
    TreeNode n4 = TreeNode(5);

    root.left = &n1;
    root.right = &n2;
    root.right->left = &n3;
    root.right->right = &n4;

    Codec c;
    string r = c.serialize(&root);

    cout << r << endl;

    c.deserialize(r);
    return 0;
}