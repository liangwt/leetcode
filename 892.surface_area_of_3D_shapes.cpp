#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int ans = 0, N = grid.size();
        pair<int, int> dir[4] = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0}};

        for (auto i = 0; i < N; ++i)
        {
            for (auto j = 0; j < N; ++j)
            {
                int cur = grid[i][j];

                // four directions
                for (auto f : dir)
                {
                    int side;

                    if (i + f.first < 0 || i + f.first >= N || j + f.second < 0 || j + f.second >= N)
                    {
                        side = 0;
                    }
                    else
                    {
                        side = grid[i + f.first][j + f.second];
                    }

                    if (cur > side)
                    {
                        ans += (cur - side);
                    }
                }

                // top and bottom
                if (cur != 0)
                {
                    ans += 2;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> g1 = {{2}};
    assert(s.surfaceArea(g1) == 10);

    vector<vector<int>> g2 = {{1, 2}, {3, 4}};
    assert(s.surfaceArea(g2) == 34);

    vector<vector<int>> g3 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    assert(s.surfaceArea(g3) == 32);

    vector<vector<int>> g4 = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    assert(s.surfaceArea(g4) == 46);

    vector<vector<int>> g5 = {{0}};
    assert(s.surfaceArea(g5) == 0);
}