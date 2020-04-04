/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * [Trapping Rain Water](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 * 
 * Example:
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

/**
 * 先记录每个位置左边的最大值
 * 
 * 再记录每个位置右边的最大值
 * 
 * 这时候对于每一个位置来说，左边最大值和右边最大值中最小的那个就是水位能到达的高度
 * 如果这个高度比自己高，那这个差值就是储水量
 * 把每一个位置的储水量算进来就是最后的结果
 */

#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        vector<int> t(len);
        int ans = 0, mx = 0;
        
        for(int j=len-1;j>=0;--j){
            mx = max(height[j], mx);
            t[j] = mx;
        }

        mx = 0;
        for(int i=0;i<len;++i){
            mx = max(height[i], mx);
            ans +=  (min(t[i], mx) - height[i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(s.trap(height) == 6);

    return 0;
}
