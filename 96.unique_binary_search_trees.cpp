// 设 对于 1..n 个数
//     G[n] 代表 n 个节点可以构成的二叉搜索树数量
//     F[i, n] 代表 n 个节点，其中以 i 作为根节点可以构成的二叉搜索树数量

// 把 1..n 每一个数作为根节点所形成的二叉树数量加起来就为 G[n]
//
// 即：`G[n] = F[1, n] + F[2, n] + ... + F[n, n]`

// 对于以 i 作为根节点构成的二叉搜索树，i 把  1..n 分成了两部分，每一部分能形成的二叉树数量分别为 `G[i-1]`和 `G[n-i]`
//
// 即：`F[i, n] = G[i-1] * G[n-i]`

// 综上
// `G[n] = G[0] * G[n-1] + G[1] * G[n-2] + ... + G[n-1] * G[0]`

#include <vector>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n < 2)
        {
            return 1;
        }

        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        return G[n];
    }
};

int main()
{
    Solution s;
    assert(s.numTrees(1) == 1);
    assert(s.numTrees(2) == 2);
    assert(s.numTrees(3) == 5);
    assert(s.numTrees(4) == 14);
}