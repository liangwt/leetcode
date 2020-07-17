#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (right - left) / 2 + left;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return left;
    }
};

int main()
{
    Solution s;
    
    vector<int> n1 = {1, 3, 5, 6};
    assert(s.searchInsert(n1, 5) == 2);

    vector<int> n2 = {1, 3, 5, 6};
    assert(s.searchInsert(n1, 2) == 1);

    vector<int> n3 = {1, 3, 5, 6};
    assert(s.searchInsert(n1, 7) == 4);

    vector<int> n4 = {1, 3, 5, 6};
    assert(s.searchInsert(n4, 0) == 0);
}