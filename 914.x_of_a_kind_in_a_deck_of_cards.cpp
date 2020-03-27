#include <unordered_map>
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> table;

        for (auto d : deck)
        {
            table[d]++;
        }

        int ans = 0;
        for (auto t : table)
        {
            ans = gcd(t.second, ans);
        }

        return ans >= 2;
    }

    int gcd(int a, int b)
    {
        while (b)
        {
            int t = a % b;
            a = b;
            b = t;
        }

        return a;
    }
};

int main()
{
    Solution s;

    vector<int> d1 = {1, 2, 3, 4, 4, 3, 2, 1};
    assert(s.hasGroupsSizeX(d1));

    vector<int> d2 = {1, 1, 1, 2, 2, 2, 3, 3};
    assert(!s.hasGroupsSizeX(d2));

    vector<int> d3 = {1};
    assert(!s.hasGroupsSizeX(d3));

    vector<int> d4 = {1, 1};
    assert(s.hasGroupsSizeX(d4));

    vector<int> d5 = {1, 1, 2, 2, 2, 2};
    assert(s.hasGroupsSizeX(d5));

    vector<int> d6 = {};
    assert(!s.hasGroupsSizeX(d6));
}