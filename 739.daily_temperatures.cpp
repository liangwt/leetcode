#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> ans(T.size(), 0);
        stack<int> sk;

        for (int i = 0; i < T.size(); i++)
        {
            while (!sk.empty() && T[sk.top()] < T[i])
            {
                ans[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> a1 = {1, 1, 4, 2, 1, 1, 0, 0};
    assert(s.dailyTemperatures(t1) == a1);
}