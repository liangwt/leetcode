#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> cur;
        helper(n, k, 0, cur, result);

        return result;
    }

    void helper(int n, int k, int idx, vector<int> &cur, vector<vector<int>> &result)
    {
        if (cur.size() == k)
        {
            result.push_back(cur);
            return;
        }

        for (int i = idx + 1; i <= n; i++)
        {
            cur.push_back(i);
            helper(n, k, i, cur, result);
            cur.pop_back();
        }
    }
};

int main()
{
    Solution s;

    assert(s.combine(4, 2) == vector<vector<int>>({{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}));
    assert(s.combine(4, 1) == vector<vector<int>>({{1}, {2}, {3}, {4}}));
}