#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<bool>> visited;
    int b;

    vector<pair<int, int>> dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        b = image[sr][sc];
        visited = vector<vector<bool>>(image.size(), vector<bool>(image[0].size(), false));

        dfs(image, sr, sc, newColor);

        return image;
    }

    void dfs(vector<vector<int>> &image, int y, int x, int newColor)
    {
        if (visited[y][x] || image[y][x] != b)
        {
            return;
        }

        image[y][x] = newColor;
        visited[y][x] = true;

        for (const auto &d : dir)
        {
            int dy = y + d.first;
            int dx = x + d.second;

            if (dy >= 0 && dy < image.size() && dx >= 0 && dx < image[0].size() && !visited[dy][dx])
            {
                dfs(image, dy, dx, newColor);
            }
        }
        return;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> v1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    assert(s.floodFill(v1, 1, 1, 2) == vector<vector<int>>({{2, 2, 2}, {2, 2, 0}, {2, 0, 1}}));
}