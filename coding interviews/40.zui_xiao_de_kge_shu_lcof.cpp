// @link https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
#include <string>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
        {
            return {};
        }

        priority_queue<int> q;

        for (int i = 0; i < k && i < arr.size(); i++)
        {
            q.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++)
        {
            int t = q.top();
            if (t > arr[i])
            {
                q.pop();
                q.push(arr[i]);
            }
        }

        int s = q.size();
        vector<int> result = vector<int>(s);

        for (int i = 0; i < s; i++)
        {
            result[i] = q.top();
            q.pop();
        }

        return result;
    }
};

int main()
{
    Solution s;

    auto equal = [](vector<int> a, vector<int> b) -> bool {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    };

    vector<int> arr1 = {3, 2, 1};
    assert(equal(s.getLeastNumbers(arr1, 2), vector<int>({2, 1})));

    vector<int> arr2 = {0, 1, 2, 1};
    assert(equal(s.getLeastNumbers(arr2, 1), vector<int>{0}));

    vector<int> arr3 = {0, 1, 2, 1};
    assert(equal(s.getLeastNumbers(arr3, 6), vector<int>{0, 1, 2, 1}));

    vector<int> arr4 = {0, 0, 0, 2, 0, 5};
    assert(equal(s.getLeastNumbers(arr4, 0), vector<int>{}));
}