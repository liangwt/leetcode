/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * [Largest Rectangle in Histogram](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 *
 * [Largest Rectangle in Histogram](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 *
 * Example:
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 */

/**
 * 解题思路参考：https://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
 *
 * [monotone stack](https://images0.cnblogs.com/blog/466943/201307/17223405-ba207c5828a54eca8ca81e04175aa3bd.png)
 *
 * 假设在递增的过程中我们遇到了一个递减的bar A，相当于栈顶元素是一个局部最高点
 *
 * 所以在单调栈中比它大的栈要依次出栈，直到比这个bar小的元素
 *
 * 在依次出栈的同时计算到A（不包含）形成的矩形面积
 * 因为是栈元素是递增的，所以此时新的栈顶B到A的高度都是大于出栈的元素C的高度的，也就是说在A和B之间C是短板，形成的矩形面积就为C的高度*A到B的距离
 *
 * 为什么只需要计算比此bar高的元素？因为此bar是短板决定了之后所形成的矩形面积，对于比它更低的bar形成的面积也会把它包含在内
 *
 * 在最后我们让0进入单调栈，于是栈中所有元素都会被当成短板被计算，这也是为什么在中间只需要关心比递减bar高的bar的原因
 *
 */
#include <vector>
#include <stack>

#include <assert.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        int i = 0, size = heights.size();
        int ret = 0;
        stack<int> sk;

        while (i < size) {
            if (sk.empty() || heights[sk.top()] <= heights[i]) {
                sk.push(i++);
            } else {
                int t = sk.top();
                sk.pop();
                ret = max(ret, heights[t] * (sk.empty() ? i : (i - sk.top() - 1)));
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> h1 = {2, 1, 5, 6, 2, 3};
    assert(s.largestRectangleArea(h1) == 10);

    vector<int> h2 = {};
    assert(s.largestRectangleArea(h2) == 0);

    return 0;
}