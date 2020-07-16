#include <vector>

#define WHITE 0
#define RED 1
#define GREEN -1

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // 0  - no-color
        // 1  - red color
        // -1 - green color
        vector<int> colored(graph.size(), WHITE);

        for (int i = 0; i < graph.size(); i++)
        {
            if (colored[i] == WHITE && !dfs(graph, colored, i, RED))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &colored, int i, int color)
    {

        if (colored[i] != WHITE)
        {
            return colored[i] == color;
        }

        colored[i] = color;

        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!dfs(graph, colored, graph[i][j], -color))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> n1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    assert(s.isBipartite(n1) == true);

    vector<vector<int>> n2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    assert(s.isBipartite(n2) == false);
}