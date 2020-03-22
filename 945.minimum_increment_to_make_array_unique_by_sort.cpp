#include <assert.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 先排序，再依次遍历数组元素，若当前元素小于等于它前一个元素，则将其变为前一个数+1。
    int minIncrementForUnique(vector<int> &A)
    {
        int ans = 0;
        int len = A.size();
        sort(A.begin(), A.end());

        for (int i = 1; i < len; ++i)
        {
            int r = A[i], l = A[i - 1];

            if (r <= l)
            {
                ans += (l - r + 1);
                A[i] = l + 1;
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