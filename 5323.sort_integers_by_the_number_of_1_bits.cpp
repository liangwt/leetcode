#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> temp;
        // 计算数组中每个值的二进制表示中数字 1 的数目
        for (auto i : arr)
        {
            int n = 0, t = i;
            while (i > 0)
            {
                n += i & 1;
                i = i >> 1;
            }
            cout << n << endl;

            temp.push_back(make_pair(n, t));
        }

        // 按照二进制表示中数字 1 的数目排序
        sort(temp.begin(), temp.end());

        // 获取结果
        vector<int> result;
        for (auto i : temp)
        {
            result.push_back(i.second);
        }
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> r2 = {0, 1, 2, 4, 8, 3, 5, 6, 7};
    assert(s.sortByBits(arr1) == r2);
}