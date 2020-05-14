#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (const auto &num : nums)
        {
            ans ^= num;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {2, 2, 1};
    assert(s.singleNumber(n1) == 1);

    vector<int> n2 = {4, 1, 2, 1, 2};
    assert(s.singleNumber(n2) == 4);
}