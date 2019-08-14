/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 *              jump length is 0, which makes it impossible to reach the last index.
 */

/**
 * 维护一个当前的能量值cur，初始化为1
 * 于是逐个遍历数组的每一个元素
 *   每当访问一个元素，cur就会失去1能量
 *   如果当前元素比剩余能量大则补充能量，反之则继续往前
 *    即 cur = max(nums[i], cur);
 * 
 * 如果在遍历过程中cur能量小于0了，则不能继续往前跳了
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.empty())
        {
            return true;
        }

        int cur = 1;

        for (size_t i = 0; i < nums.size(); i++)
        {
            cur--;
            if (cur < 0)
            {
                return false;
            }
            cur = max(nums[i], cur);
        }

        return cur >= 0;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};

    auto r = Solution().canJump(nums);

    cout << r << endl;
}