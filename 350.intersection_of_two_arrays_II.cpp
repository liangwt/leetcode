#include <vector>
#include <unordered_map>
#include "include/header/utils.hpp"

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> t;

        for (const auto &n : nums1)
        {
            t[n]++;
        }

        vector<int> ans;

        for (const auto &n : nums2)
        {
            if (t.find(n) != t.end() && t[n] > 0)
            {
                t[n]--;
                ans.push_back(n);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 2, 2, 1};
    vector<int> n2 = {2, 2};
    assert(vector_equal(s.intersect(n1, n2), vector<int>({2, 2})));

    vector<int> n3 = {4, 9, 5};
    vector<int> n4 = {9, 4, 9, 8, 4};
    assert(vector_equal(s.intersect(n3, n4), vector<int>({4, 9})));
}