/**
 * 1. 对于一个不在数组中的最小正整数，它一定在[1,len+1]这个范围内
 *    1.1 如果数组中出现了 [1,N] 则 N+1 为不在数组的最小正整数
 *    1.2 如果数组中没有出现 [1,N]，则没有出现的那个数为不在数组的最小正整数
 * 2. 输入数组的长度正好为N，把输入数组作为一个哈希表。如果一个数 n 在[1,N]范围，则标记数组对应n-1位置。
 *    数组中没有被标记的位置则为最小正整数，如果全部被标记则 N+1为最小正整数
 * 3. 可以通过把负数全部变成 N+1，让数组全部都是正数。所以标记就是把数字变为负数。
 **/
#include <vector>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = len + 1;
            }
        }

        for (int i = 0; i < len; i++)
        {
            int n = abs(nums[i]);

            if (n <= len)
            {
                nums[n - 1] = abs(nums[n - 1]) * -1;
            }
        }

        int ans = len + 1;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
            {
                ans = i + 1;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {1, 2, 0};
    assert(s.firstMissingPositive(a1) == 3);

    vector<int> a2 = {3, 4, -1, 1};
    assert(s.firstMissingPositive(a2) == 2);

    vector<int> a3 = {7, 8, 9, 11, 12};
    assert(s.firstMissingPositive(a3) == 1);
}