// 对于两个有序数组寻找中位数，首先分别在两个数组中各找到一条分界线，分界线位于索引i（num1中）和j（num2中）的右侧，他们满足
// 1. nums1中i的左侧 + nums2中j的左侧的元素个数和为 (len(nums1) + len(num2) + 1) / 2
//    也就是说左侧的个数为总个数的一半（总数为偶数）或者总个数一半加一（总数为奇数）
// 2. 对于分界线位置两侧的元素 num1[i-1] < num2[j] && num1[i] > num2[j-1]
//    也就是说，分界线左侧的数据要小于右侧

// 在找到的这条分界线后

// 如果两个数组总个数为奇数，则为分界线左侧两个元素中的最大值
// 如果两个数组总个数为偶数，则为分界线左侧最大值和分界线右侧最小值的平均数

#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len_n1 = nums1.size();
        int len_n2 = nums2.size();
        // 位于中位数左侧的个数
        int left_total = (len_n1 + len_n2 + 1) / 2;

        int left = 0, right = len_n1 - 1;
        while (left <= right)
        {
            int i = (right - left) / 2 + left;
            int j = left_total - i;

            if (j <= 0)
            {
                right = i - 1;
                continue;
            }

            if (j > len_n2)
            {
                left = i + 1;
                continue;
            }

            if (nums1[i] < nums2[j - 1])
            {
                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }

        int i = left;
        int j = left_total - i;

        int n1_left_max = i == 0 ? INT_MIN : nums1[i - 1];
        int n2_left_max = j == 0 ? INT_MIN : nums2[j - 1];
        int left_max = max(n1_left_max, n2_left_max);

        int n1_right_min = i >= len_n1 ? INT_MAX : nums1[i];
        int n2_right_min = j >= len_n2 ? INT_MAX : nums2[j];
        int right_min = min(n1_right_min, n2_right_min);

        if (((len_n1 + len_n2) % 2) == 1)
        {
            return left_max;
        }
        else
        {
            return double((left_max + right_min) / 2.0);
        }
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 3};
    vector<int> n2 = {2};
    assert(s.findMedianSortedArrays(n1, n2) - 2.0 < 1e-6);

    vector<int> n3 = {1, 2};
    vector<int> n4 = {3, 4};
    assert(s.findMedianSortedArrays(n3, n4) - 2.5 < 1e-6);

    return 0;
}