/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Example 1:
 *
 * Input: [3,2,3]
 * Output: 3
 * Example 2:
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 */

/**
 * 思路1：
 *  使用map来记录每一个数字出现的次数，空间和时间复杂度都是O(n)
 *
 * 思路2：
 *  使用摩尔投票法(moore voting)的方式：
 *
 *   先假设第一个数是过半的元素，同时设置一个计数器置1
 *   依次往下遍历，如果遇到和假定元素相同的值，则计数器+1。如果遇到和假定元素不相同的值，则计数器-1
 *   当计数器为0时，说明与假定值不一样的元素个数已经比假定值个数多了，重新选定下一个元素作为假定值
 *   当遍历完成，假定值就是最后结果
 */

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int ct = 0, ret = nums[0];
        for (auto num : nums) {
            if (ct == 0) {
                ret = num;
            }

            if (ret == num) {
                ct++;
            } else {
                ct--;
            }
        }

        return ret;
    }
};

int main() {
    Solution s;

    vector<int> n1 = {3, 2, 3};
    assert(s.majorityElement(n1) == 3);

    vector<int> n2 = {2, 2, 1, 1, 1, 2, 2};
    assert(s.majorityElement(n2) == 2);

    return 0;
}