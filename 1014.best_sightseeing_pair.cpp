#include <vector>

using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &A)
    {
        int mx = INT_MIN, ans = 0, len = A.size();

        vector<int> sub_max(len, INT_MIN);

        for (int i = len - 1; i >= 0; i--)
        {
            mx = max(mx, A[i] - i);
            sub_max[i] = mx;
        }

        for (int i = 0; i < len - 1; i++)
        {
            ans = max(ans, A[i] + i + sub_max[i + 1]);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {8, 1, 5, 2, 6};
    assert(s.maxScoreSightseeingPair(a1) == 11);
}