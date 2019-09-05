/**
 * In this problem, a tree is an undirected graph that is connected and has no cycles.
 *
 * The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
 *
 * The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.
 *
 * Example 1:
 * Input: [[1,2], [1,3], [2,3]]
 * Output: [2,3]
 * Explanation: The given undirected graph will be like this:
 *   1
 *  / \
 * 2 - 3
 * Example 2:
 * Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * Output: [1,4]
 * Explanation: The given undirected graph will be like this:
 * 5 - 1 - 2
 *     |   |
 *     4 - 3
 * Note:
 * The size of the input 2D-array will be between 3 and 1000.
 * Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 *
 * Update (2017-09-26):
 * We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
 */

/**
 * 使用并交集
 *
 * 对于一个不相交的动态集合{S1, S2, ... Sk} 使用一个代表来标识每个集合，它也是集合中的一个成员
 *
 * 设x表示其中的一个对象
 *
 * MAKE_SET(x): 建立一个新的集合，它的唯一成员也是代表为x
 * UNION(x, y): 将包含x, y的两个集合合并成一个集合
 * FIND(x): 返回包含x的集合的代表
 *
 * 有两种方式可以实现不相交集合
 *
 * 一、链表
 *
 * 集合对象包含head和tail，其中每一个元素按照链表方式连接并有一个指向集合对象的指针
 *
 *      _____________________________
 *     |           |        |        |
 *     v           |        |        |
 * | head-|------> f -----> g -----> d
 * |      |                          ^
 * |      |                          |
 * | tail-|--------------------------
 *
 *
 * 二、有根树
 *
 *  树中每个成员指向自身的父节点，树的根节点指向自己并且代表是集合的代表
 *
 *          __
 *         |  |
 *         v  |
 *         c--
 *        ^ ^
 *       /   \
 *      h    e
 *     ^
 *    /
 *   b
 *
 */

/**
 * 此题目我们实现一个并交集UF
 * 使用map的key作为节点值，value作为父节点
 *
 * 通过FIND(x), FIND(y)来的到边(x, y)各自所在的集合代表
 *
 * 如果是同一个值，说明边(x, y)的两个端点已经在同一个集合中了，也就是说通过其他路径可以联通了
 *
 * 把所有的边都依次加入到集合中，最后一个两端点已经联通的边就是题目的结果
 *
 */

#include <vector>
#include <unordered_map>

#include <assert.h>

using namespace std;


class UF {
private:
    unordered_map<int, int> _table;
public:
    void make(int x) {
        _table[x] = x;
    }

    int find(int x) {
        int root = x;

        while (_table[root] != root) {
            root = _table[root];
        }

        if (root == 0) {
            _table[x] = x;
            return x;
        }

        return root;
    }

    bool merge(int x, int y) {
        int i = find(x), j = find(y);

        if (i == j) {
            return false;
        }

        _table[i] = j;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        UF uf;
        vector<int> ret;

        for (auto &edge: edges) {
            if (!uf.merge(edge[0], edge[1])) {
                ret = edge;
            }
        }

        return ret;
    }
};

int main() {
    Solution s;

    vector<vector<int>> e1 = {{1, 2},
                              {1, 3},
                              {2, 3}};
    assert(s.findRedundantConnection(e1) == vector<int>({2, 3}));

    vector<vector<int>> e2 = {{1, 2},
                              {2, 3},
                              {3, 4},
                              {1, 4},
                              {1, 5}};
    assert(s.findRedundantConnection(e2) == vector<int>({1, 4}));


    return 0;
}