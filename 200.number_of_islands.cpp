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
 * 使用深度优先搜索
 *
 * 以一个1的元素为入口，遍历其上下左右的位置，遇到1则继续搜索，遇到0时说明抵达边界，标记访问过之后返回，当函数返回时就获得了一个由1连在一起的孤岛
 *
 * 逐个访问没有被访问过，且为1的入口，最后就可以得到有多少块孤岛
 */

#include <vector>

using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dir = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    int len_x;
    int len_y;
    vector<vector<bool>> visited;

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
        {
            return 0;
        }

        len_x = grid[0].size();
        len_y = grid.size();
        visited = vector(len_y, vector(len_x, false));

        int ans = 0;
        for (int i = 0; i < len_y; ++i)
        {
            for (int j = 0; j < len_x; ++j)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    visited[i][j] = true;
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        for (const auto &[x, y] : dir)
        {
            int xx = j + x;
            int yy = i + y;
            if (xx >= 0 && xx < len_x && yy >= 0 && yy < len_y && !visited[yy][xx] && grid[yy][xx] == '1')
            {
                visited[yy][xx] = true;
                dfs(grid, yy, xx);
            }
        }
    }
};

int main()
{
    Solution s;

    vector<vector<char>> g1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    assert(s.numIslands(g1) == 3);

    vector<vector<char>> g2 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    assert(s.numIslands(g2) == 1);

    vector<vector<char>> g3 = {
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    assert(s.numIslands(g3) == 0);

    vector<vector<char>> g4 = {};
    assert(s.numIslands(g4) == 0);

    return 0;
}