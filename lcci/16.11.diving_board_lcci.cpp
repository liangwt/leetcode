#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> divingBoard(int shorter, int longer, int k)
    {
        if (k == 0)
        {
            return {};
        }

        if (shorter == longer)
        {
            return vector<int>(1, shorter * k);
        }

        // 设 i 块 shorter，则有 k-i 块 longer
        // 只要证明 i 从 0 到 k，每个长度length = i * longer + (k-i) * shorter都不一样

        vector<int> ans(k + 1);

        for (int i = 0; i <= k; i++)
        {
            ans[i] = i * longer + (k - i) * shorter;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    assert(s.divingBoard(1, 1, 10) == vector<int>({10}));
    assert(s.divingBoard(1, 2, 3) == vector<int>({3, 4, 5, 6}));
    assert(s.divingBoard(1, 2, 0) == vector<int>({}));
}