/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    }
};

int main() {
    Solution s;

    vector<int> n1 = {1, 3};
    vector<int> n2 = {2};
    assert(s.findMedianSortedArrays(n1, n2) - 2.0 < 1e-6);

    vector<int> n3 = {1, 2};
    vector<int> n4 = {3, 4};
    assert(s.findMedianSortedArrays(n3, n4) - 2.0 < 1e-6);

    return 0;
}