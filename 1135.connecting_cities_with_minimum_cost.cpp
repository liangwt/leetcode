/**
 * There are N cities numbered from 1 to N.
 * 
 * You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)
 * 
 * Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.
 * 
 *  
 * Example 1:
 * 
 * [Example 1](https://assets.leetcode.com/uploads/2019/04/20/1314_ex2.png)
 * 
 * Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
 * Output: 6
 * Explanation: 
 * Choosing any 2 edges will connect all cities so we choose the minimum 2.
 * 
 * Example 2:
 * 
 * [Example 2](https://assets.leetcode.com/uploads/2019/04/20/1314_ex1.png)
 * 
 * Input: N = 4, connections = [[1,2,3],[3,4,4]]
 * Output: -1
 * Explanation: 
 * There is no way to connect all cities even if all edges are used.
 * Note:
 * 
 * 1 <= N <= 10000
 * 1 <= connections.length <= 10000
 * 1 <= connections[i][0], connections[i][1] <= N
 * 0 <= connections[i][2] <= 10^5
 * connections[i][0] != connections[i][1]
 */

/**
 * 使用科鲁兹卡尔算法：
 *  1. 把所有边按照权重来排序 
 *  2. 按照排序后的顺序，对于两个端点不在同一个集合中的边，加入到最小生成树结果中，并合并连接的两个集合
 *  3. 如果最后只剩下一个集合则说明存在最小生成树
 */
#include <unordered_map>
#include <vector>

#include <assert.h>

using namespace std;

class UF {
private:
    unordered_map<int, int> _table;
    unordered_map<int, int> _size;

    int num = 0;

public:
    UF(int size) {
        _table = unordered_map<int, int>(size);
        _size = unordered_map<int, int>(size);
    }

    int getNum() {
        return num;
    }

    void make(int x) {
        _table[x] = x;
        _size[x] = 0;
        num++;
    }

    int find(int x) {
        int root = x;
        while (root != _table[root]) {
            root = _table[root];
        }

        return root == 0 ? -1 : root;
    }

    bool merge(int x, int y) {
        int i = find(x);
        if (i == -1) {
            make(x);
            i = x;
        }

        int j = find(y);
        if (j == -1) {
            make(y);
            j = y;
        }

        if (i == j) {
            return false;
        }

        if (_size[i] > _size[j]) {
            _table[j] = i;
            _size[i] += _size[j];
        } else {
            _table[i] = j;
            _size[j] += _size[i];
        }

        num--;

        return true;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>> &connections) {
        sort(connections.begin(), connections.end(), [](vector<int> x, vector<int> y) -> bool {
            return x[2] < y[2];
        });

        UF uf(N);
        int sum = 0;

        for (auto connection: connections) {
            if (uf.merge(connection[0], connection[1])) {
                sum += connection[2];
            }
        }

        return uf.getNum() == 1 ? sum : -1;
    }
};

int main() {
    Solution s;

    vector<vector<int>> c1 = {
        {1, 2, 5},
        {1, 3, 6},
        {2, 3, 1},
    };

    assert(s.minimumCost(3, c1) == 6);

    vector<vector<int>> c2 = {
        {1, 2, 3},
        {3, 4, 4},
    };
    assert(s.minimumCost(4, c2) == -1);

    return 0;
}