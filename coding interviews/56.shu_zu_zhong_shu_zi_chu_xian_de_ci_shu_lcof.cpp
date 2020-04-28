#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int t = 0;

        for (const auto &num : nums)
        {
            t ^= num;
        }

        int h = 1;

        while (!(h & t))
        {
            h = (h << 1);
        }

        int a = 0, b = 0;

        // 全部数字异或的结果中，某一位是1，可以按照这一位是否为1把全部数组分成两组
        for (const auto &num : nums)
        {
            if (num & h)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }

        return {a, b};
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {4, 1, 4, 6};
    assert(s.singleNumbers(n1) == vector<int>({1, 6}));

    vector<int> n2 = {1, 2, 10, 4, 1, 4, 3, 3};
    assert(s.singleNumbers(n2) == vector<int>({10, 2}));
}