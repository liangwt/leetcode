#include <vector>

using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        vector<int> nums;
        while (num != 0)
        {
            nums.push_back(num % 10);
            num = num / 10;
        }

        reverse(nums.begin(), nums.end());

        int len = nums.size();
        vector<int> dp(len + 1, 1);

        for (int i = 1; i < len; i++)
        {
            int t = dp[i];
            int n = nums[i - 1] * 10 + nums[i];

            if (n >= 10 && n <= 25)
            {
                t += dp[i - 1];
            }

            dp[i + 1] = t;
        }

        return dp[len];
    }
};

int main()
{
    Solution s;
    assert(s.translateNum(12258) == 5);
    assert(s.translateNum(0) == 1);
}