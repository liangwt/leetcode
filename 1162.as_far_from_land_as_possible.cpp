#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    /**
     * 把所有陆地（1）送入初始队列，进行多源bfs 
     * @ref https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/jian-dan-java-miao-dong-tu-de-bfs-by-sweetiee/
     **/
    int maxDistance(vector<vector<int>> &grid)
    {
        int len_x = grid[0].size(), len_y = grid.size();

        queue<pair<int, int>> Q;
        vector<vector<int>> visited(len_y, vector<int>(len_x, -1));

        // 把所有陆地放入初始队列
        for (int i = 0; i < len_y; ++i)
        {
            for (int j = 0; j < len_x; ++j)
            {
                if (grid[i][j] == 1)
                {
                    Q.push({i, j});
                    visited[i][j] = 0;
                }
            }
        }

        // 没有陆地
        if (Q.empty())
        {
            return -1;
        }

        pair<int, int> point;

        // 从多源的陆地开始bfs
        while (!Q.empty())
        {
            point = Q.front();
            Q.pop();

            auto [x, y] = point;

            for (const auto &[xx, yy] : dir)
            {
                int dx = x + xx;
                int dy = y + yy;

                if (dx >= 0 && dx < len_x &&
                    dy >= 0 && dy < len_y &&
                    visited[dx][dy] == -1)
                {
                    Q.push({dx, dy});
                    visited[dx][dy] = visited[x][y] + 1;
                }
            }
        }

        return visited[point.first][point.second] == 0 ? -1 : visited[point.first][point.second];
    }
};

int main()
{
    Solution s;

    vector<vector<int>> g1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    assert(s.maxDistance(g1) == 2);

    vector<vector<int>> g2 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    assert(s.maxDistance(g2) == 4);

    vector<vector<int>> g4 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    assert(s.maxDistance(g4) == -1);

    vector<vector<int>> g5 = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    assert(s.maxDistance(g5) == -1);
}