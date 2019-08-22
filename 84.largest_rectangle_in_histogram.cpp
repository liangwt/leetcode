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
 * 此方式解题的思路在于找到局部最高点
 *
 * 我们认为heights[i+1] > heights[i]的都是局部最高点
 *
 * 在局部最高点之前的任何一个位置都可以把局部最高点包含在内，让矩形的面积更大
 * 所以面积最大的矩形一定是以一个局部最高点结束的
 *
 * 所以我们逐个遍历数组中的元素，当找到heights[i+1] > heights[i]的局部最高点时
 *
 * 分别计算0-i, 1-i, 2-i, ... i-i这些矩形面积，记录下最大的一个
 *
 * 当把整个数组的全部局部最高点计算完就能得到最大的矩形
 */


#include <vector>

#include <assert.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int i = 0, size = heights.size(), mx = 0;
        while (i < size) {
            if (i == size - 1 || heights[i] > heights[i + 1]) {
                int mn = heights[i];

                for (int j = i; j >= 0; --j) {
                    mn = min(mn, heights[j]);
                    mx = max(mx, mn * (i - j + 1));
                }
            }
            i++;
        }

        return mx;
    }
};

int main() {
    Solution s;
    vector<int> height = {2, 1, 5, 6, 2, 3};
    assert(s.largestRectangleArea(height) == 10);

    return 0;
}