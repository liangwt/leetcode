#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int x = obstacleGrid[0].size(), y = obstacleGrid.size();

        if (x == 0 || y == 0)
        {
            return 1;
        }

        vector<int> steps(x + 1, 0);

        steps[1] = obstacleGrid[0][0] != 1 ? 1 : 0;

        for (int i = 0; i < y; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                steps[j] = obstacleGrid[i][j - 1] != 1 ? steps[j - 1] + steps[j] : 0;
            }
        }

        return steps[x];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> n1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    assert(s.uniquePathsWithObstacles(n1) == 2);

    vector<vector<int>> n2 = {{1, 0, 0}};
    assert(s.uniquePathsWithObstacles(n2) == 0);

    vector<vector<int>> n3 = {{}};
    assert(s.uniquePathsWithObstacles(n3) == 1);
}