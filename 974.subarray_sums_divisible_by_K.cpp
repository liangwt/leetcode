#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> T = {{0, 1}};

        int ans = 0;
        int sum = 0;

        for (const auto &a : A)
        {
            sum += a;

            int t = (sum % K + K) % K;

            auto n = T.find(t);
            if (n != T.end())
            {
                ans += n->second;
            }

            T[t]++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {4, 5, 0, -2, -3, 1};
    assert(s.subarraysDivByK(n1, 5) == 7);
}