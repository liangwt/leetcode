// @link https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

#include <string>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

class Solution
{
private:
    int mm;
    int mn;
    int k;
    int ans = 0;
    vector<vector<bool>> visted;

public:
    int movingCount(int m, int n, int k)
    {
        ans = 0;
        mm = m;
        mn = n;
        this->k = k;
        visted = vector<vector<bool>>(m, vector<bool>(n, false));
        helper(0, 0);
        return ans;
    }

    void helper(int i, int j)
    {
        if (i < 0 || i >= mm || j < 0 || j >= mn || visted[i][j])
        {
            return;
        }

        if (cal(i) + cal(j) > k)
        {
            return;
        }

        visted[i][j] = true;
        ans++;
        helper(i, j + 1);
        helper(i, j - 1);
        helper(i + 1, j);
        helper(i - 1, j);
    }

    int cal(int x)
    {
        int ans = 0;
        while (x)
        {
            ans = ans + (x % 10);
            x = x / 10;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    assert(s.movingCount(2, 3, 1) == 3);
    assert(s.movingCount(3, 1, 0) == 1);
    assert(s.movingCount(0, 0, 0) == 0);
}