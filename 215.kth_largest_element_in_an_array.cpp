#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, std::greater<int>> Q(nums.begin(), nums.begin() + k);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > Q.top())
            {
                Q.pop();
                Q.push(nums[i]);
            }
        }

        return Q.top();
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {3, 2, 1, 5, 6, 4};
    assert(s.findKthLargest(n1, 2) == 5);

    vector<int> n2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    assert(s.findKthLargest(n2, 4) == 4);
}