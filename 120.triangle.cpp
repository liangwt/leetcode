#include <vector>
#include "math.h"

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j)
            {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }

        int ans = INT_MAX;

        for (const auto &i : f)
        {
            ans = min(ans, i);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    
    vector<vector<int>> n1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    assert(s.minimumTotal(n1) == 11);
}