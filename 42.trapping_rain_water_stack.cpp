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
 * 使用单调栈(Monotone Stack)
 *
 * 对于数组中某个位置，如果当前的栈为空或者栈顶元素大于此位置的值，则说明还处在下降的趋势内，则把当前位置加入到栈顶
 * 当某个位置的值大于栈顶值时，说明栈顶元素有可能形成低洼
 *
 * 这时把栈顶元素出栈
 * 如果此时栈为空说明左侧没有元素，跳过
 * 如果栈不为空，此时栈顶元素就是低洼点的左侧，当前值为右侧，则可以蓄水值就为两者最小值乘以距离
 *
 * 整个栈的值变化如下
 *
 *  0
 *  1
 *  1, 0,
 *  2
 *  2, 1
 *  2, 1, 0
 *  2, 1, 1
 *  3
 *  3, 2
 *  3, 2, 1
 *  3, 2, 2
 *  3, 2, 2, 1
 *
 */

#include <vector>
#include <stack>

#include <assert.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> sk;
        int ret = 0, i = 0;

        while (i < height.size()) {

            if (sk.empty() || height[sk.top()] >= height[i]) {
                sk.push(i++);
            } else {
                int t = sk.top();

                sk.pop();
                if (sk.empty()) {
                    continue;
                }

                int l = sk.top();

                ret += (min(height[l], height[i]) - height[t]) * (i - l - 1);
            }
        }

        return ret;
    }
};

int main() {
    Solution s;

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(s.trap(height) == 6);

    return 0;
}
