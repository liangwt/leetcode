/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 * ![The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
 *
 * Example:
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 **/

/**
 *
 * 取左右两个指针，计算两个指针位置之间的存水量。通过移动左右指针即可得到最大的存水量
 *
 * 关键在于，左右指针根据什么规则去移动。
 *
 * 很明显，当其中一个指针指向的位置比较矮时，如果此时移动另一个高的指针，两者之间距离变短了，但是高度还是受限于矮的，存水量肯定会变小
 * 所以正确的规则就是把较矮的指针往中间移动，直到两指针相遇
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = (int) height.size() - 1;
        int mx = 0, mn;

        while (left < right) {
            if (height[left] > height[right]) {
                mn = height[right];
                right--;
            } else {
                mn = height[left];
                left++;
            }

            mx = max(mn * (right - left + 1), mx);
        }

        return mx;
    }
};

int main() {
    Solution s;

    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(s.maxArea(h1) == 49);

    return 0;
}