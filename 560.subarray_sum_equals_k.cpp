/**
 * 从0到i的子数组和为  total[0,i] = nums[0] + nums[1] + ... + nums[i]
 * 从0到j的子数组和为  total[0,j] = nums[0] + nums[1] + ... + nums[j]
 * 
 * 所以可以得
 * 从i到j的子数组和为  total[i][j] = nums[i] + nums[i+1] + ... + nums[j]
 *                              = total[0][j] - total[0][i-1]
 * 
 * 对于一个子数组 total[i][j] == k
 * 转化为 
 * total[0][j] - total[0][i-1] == k
 * 再转化为
 * total[0][i-1] == total[0][j] - k 同时 0 <= i <= j <= len(nums)
 * 
 * 所以通过j++不断记录前缀和 total[0][j]，再用在哈希表里找 前缀和 total[0][j] - k 是否存在，如果存在，值就是个数
 * 
 **/
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int t = 0, ans = 0;

        for (const auto &num : nums)
        {
            t += num;
            if (mp.find(t - k) != mp.end())
            {
                ans += mp[t - k];
            }
            mp[t]++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 1, 1};
    assert(s.subarraySum(n1, 2) == 2);

    vector<int> n2 = {1, 2, 3, 4, 5};
    assert(s.subarraySum(n2, 9) == 2);

    vector<int> n3 = {};
    assert(s.subarraySum(n3, 9) == 0);

    vector<int> n4 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    assert(s.subarraySum(n4, 0) == 55);

    vector<int> n5 = {-1, -1, 1};
    assert(s.subarraySum(n5, 0) == 1);

    return 0;
}