#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> odd;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 1)
            {
                odd.push_back(i);
            }
        }

        int ans = 0;

        for (int i = 0; i < odd.size(); ++i)
        {
            if (i + k - 1 >= odd.size())
            {
                break;
            }
            // odd[i] ~ odd[i+k-1]
            // 左侧可选 odd[i-1] ~ odd[i]
            // 右侧可选 odd[i+k-1] ~ odd[i+k]
            int l1;
            if (i - 1 < 0)
            {
                l1 = -1;
            }
            else
            {
                l1 = odd[i - 1];
            }

            int r1;
            if (i + k >= odd.size())
            {
                r1 = nums.size();
            }
            else
            {
                r1 = odd[i + k];
            }

            ans += (odd[i] - l1) * (r1 - odd[i + k - 1]);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 1, 2, 1, 1};
    assert(s.numberOfSubarrays(n1, 3) == 2);

    vector<int> n2 = {2, 4, 6};
    assert(s.numberOfSubarrays(n2, 1) == 0);

    vector<int> n3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    assert(s.numberOfSubarrays(n3, 2) == 16);
}