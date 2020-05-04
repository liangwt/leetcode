/**
 * 思路：
 * 按照贪心算法
 * 
 * 1. 维护一个上次跳跃能到达的最右端的位置 end
 * 2. 逐个遍历数组，在达到end之前的不断计算可以达到的最右端，即下一跳的最远位置 right
 * 3. 在达到上一次跳跃的位置end的时候，说明该进行本次跳跃了，本次跳跃的最远位置是right，即 end = right
 *    本次跳跃不一定是在end的位置跳跃的，只要是在end之前的位置都可以。而end表示必须跳跃的时机
 * 
 * 4. 如果最后一次跳跃正好落在末尾元素上，那么遍历到末尾时其实已经不用再跳了。
 *    所以干脆不遍历最后一个元素，反正肯定可以跳到最后
 **/

#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int right = 0, ans = 0, end = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            right = max(right, nums[i] + i);

            if (i == end)
            {
                end = right;
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {2, 3, 1, 1, 4};
    assert(s.jump(n1) == 2);
}