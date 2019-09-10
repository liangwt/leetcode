/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Example:
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

/**
 *  对于一个数组[a, b, c, d]
 *
 *  如果从前计算乘积得
 *
 *   [a, ab, abc]
 *
 *  从后计算乘积得
 *
 *   [dcb , dc, d]
 *
 *  对于两个数组前后补1，然后对应相乘就可以得到这个问题得解
 *
 *  [1, a, ab, abc] * [dcb, dc, d, 1] = [dcb, adc, abd, abc]
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = (int) nums.size();

        vector<int> front(len, 1), back(len, 1), result(len);

        // 从前遍历
        for (int i = 0; i < len - 1; i++) {
            front[i + 1] = front[i] * nums[i];
        }

        // 从后遍历
        for (int i = len - 1; i > 0; i--) {
            back[i - 1] = back[i] * nums[i];
        }

        // 计算结果
        for (int i = 0; i < len; i++) {
            result[i] = front[i] * back[i];
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {1, 2, 3, 4};
    assert(s.productExceptSelf(n1) == vector<int>({24, 12, 8, 6}));

    vector<int> n2 = {1};
    assert(s.productExceptSelf(n2) == vector<int>({1}));

    return 0;
}