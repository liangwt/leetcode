#include <vector>
#include <string>
#include <unordered_set>
#include <assert.h>

using namespace std;

/**
 * 这是一个通用的字典树，并不止适用于此题 
 **/
class TrieNode
{
public:
    // 当前节点的字符
    char val;
    // 当前节点到根节点的长度，也是字符串的长度
    int prefix;
    // 根节点到当前节点组成的字符串出现的次数，0就说明没有
    int count;
    // 快速获得子节点的数量，可以通过此字段快速获知此节点是否为叶子节点
    int childNum;
    // 子节点
    TrieNode *child[26];

public:
    TrieNode(char c)
    {
        val = c;
        prefix = 0;
        count = 0;
        childNum = 0;
        memset(child, 0, sizeof(child));
    }

    static TrieNode *searchPrefix(TrieNode *root, string prefix)
    {
        if (root == nullptr || prefix.size() == 0)
            return nullptr;

        for (const auto &w : prefix)
        {
            root = root->child[w - 'a'];
            if (!root)
            {
                return nullptr;
            }
        }

        return root;
    }

    static TrieNode *insert(TrieNode *root, string word)
    {
        if (root == nullptr || word.size() == 0)
            return nullptr;

        // 逐个字符插入到子节点上，如果不存在则创建
        for (const auto &w : word)
        {
            int k = w - 'a';

            TrieNode *node = root->child[k];
            if (!node)
            {
                node = new TrieNode(w);
                node->prefix = root->prefix + 1;

                root->child[k] = node;
                root->childNum++;
            }
            root = node;
        }

        root->count++;
        return root;
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        auto root = new TrieNode('\0');
        unordered_set<TrieNode *> table;

        for (const auto &word : words)
        {
            table.insert(TrieNode::insert(root, string(word.rbegin(), word.rend())));
        }

        int ans = 0;
        for (const auto &t : table)
        {
            if (t->childNum == 0)
            {
                ans += (t->prefix + 1);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<string> w1 = {"time", "me", "bell"};
    assert(s.minimumLengthEncoding(w1) == 10);

    vector<string> w2 = {};
    assert(s.minimumLengthEncoding(w2) == 0);

    vector<string> w3 = {"time", "time", "time", "time"};
    assert(s.minimumLengthEncoding(w3) == 5);
}