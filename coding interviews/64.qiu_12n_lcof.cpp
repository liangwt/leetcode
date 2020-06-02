#include "assert.h"

using namespace std;

class Solution
{
public:
    int sumNums(int n)
    {
        bool arr[n][n + 1];
        return sizeof(arr) >> 1;
    }
};

int main()
{
    Solution s;
    assert(s.sumNums(3) == 6);
    assert(s.sumNums(9) == 45);
}