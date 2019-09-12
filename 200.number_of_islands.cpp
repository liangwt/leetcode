/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 */

/**
 * 使用深度优先搜索，
 *
 * 以一个1的元素为入口，遍历其上下左右的位置，遇到1则继续搜索，遇到0时说明抵达边界，标记访问过之后返回，当函数返回时就获得了一个由1连在一起的孤岛
 *
 * 逐个访问没有被访问过，且为1的入口，最后就可以得到有多少块孤岛
 */

#include <vector>

using namespace std;

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

class Solution {
public:
    int numIslands(vector <vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        auto visited = vector < vector < bool >> (grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    _helper(i, j, grid, visited);
                    result++;
                }
            }
        }

        return result;
    }

    void _helper(int i, int j, vector <vector<char>> &grid, vector <vector<bool>> &visited) {
        visited[i][j] = true;

        if (grid[i][j] == '1') {
            for (int k = 0; k < 4; k++) {
                int x = mx[k] + i;
                int y = my[k] + j;
                if (x < grid.size() && x >= 0 && y < grid[0].size() && y >= 0 && !visited[x][y]) {
                    _helper(x, y, grid, visited);
                }
            }
        }
    }
};

int main() {
    Solution s;

    vector <vector<char>> g1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    assert(s.numIslands(g1) == 3);

    vector <vector<char>> g2 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    assert(s.numIslands(g2) == 1);

    vector <vector<char>> g3 = {
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    assert(s.numIslands(g3) == 0);

    vector <vector<char>> g4 = {};
    assert(s.numIslands(g4) == 0);

    return 0;
}