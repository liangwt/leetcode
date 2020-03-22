#include <assert.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        // 用于统计A中每个数字出现的次数
        int table[80000] = {0};

        // 统计A中每个数字出现的次数
        for (auto a : A)
        {
            table[a]++;
        }

        // 需要多少步，它的计算可以是 (2 + 4 + 6) - (1 + 1 + 1) = 9
        int ans = 0;

        // 需要多少个未使用的数字来使之前重复的数字达到目标值
        int num = 0;

        // 如果：
        // 一个数字只出现一次，那么ans不需要变，num也不需要变
        // 一个数字出现两次及以上，那么ans可以先减去这个数字*出现的次数，例 - (1 + 1 + 1)
        //     同时num需要记录需要补多少个未使用数字
        // 一个数字未出现，且此时num大于0，说明这个数字可以是一个重复数字的目标值，于是把它加到ans去，例 (2 + 4 + 6)
        for (int i = 0; i < 80000; i++)
        {
            if (table[i] > 1)
            {
                ans -= (table[i] - 1) * i;
                num += table[i] - 1;
                continue;
            }

            if (table[i] == 0 && num > 0)
            {
                num--;
                ans += i;
                continue;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> A1 = {1, 2, 2};
    assert(s.minIncrementForUnique(A1) == 1);

    vector<int> A2 = {3, 2, 1, 2, 1, 7};
    assert(s.minIncrementForUnique(A2) == 6);

    vector<int> A3 = {};
    assert(s.minIncrementForUnique(A3) == 0);
}