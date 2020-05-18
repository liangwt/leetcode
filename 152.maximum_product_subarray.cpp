#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int len = nums.size();
        int ans = INT_MIN;

        int mx = 1, mn = 1;
        int x, n;

        for (int i = 0; i < len; i++)
        {
            x = mx;
            n = mn;

            mx = max(max(x * nums[i], n * nums[i]), nums[i]);
            mn = min(min(n * nums[i], x * nums[i]), nums[i]);

            ans = max(ans, mx);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {2, 3, -2, 4};
    assert(s.maxProduct(n1) == 6);

    vector<int> n2 = {-2, 0, -1};
    assert(s.maxProduct(n2) == 0);

    vector<int> n3 = {};
    assert(s.maxProduct(n3) == 0);
}