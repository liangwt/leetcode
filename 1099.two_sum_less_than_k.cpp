/**
 * Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K. If no i, j exist satisfying this equation, return -1.
 *
 *
 *
 * Example 1:
 *
 * Input: A = [34,23,1,24,75,33,54,8], K = 60
 * Output: 58
 * Explanation:
 * We can use 34 and 24 to sum 58 which is less than 60.
 * Example 2:
 *
 * Input: A = [10,20,30], K = 15
 * Output: -1
 * Explanation:
 * In this case it's not possible to get a pair sum less that 15.
 *
 *
 * Note:
 *
 * 1 <= A.length <= 100
 * 1 <= A[i] <= 1000
 * 1 <= K <= 2000
 */

/**
 *  排序，双指针
 */

#include <vector>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int> &A, int K) {
        int left = 0, right = (int) A.size();
        int total = -1, t = 0;

        sort(A.begin(), A.end());

        while (left < right) {
            t = K - A[left] - A[right];

            if (t >= 0) {
                total = max(total, t);

                left++;
            } else {
                right--;
            }
        }

        return total;
    }
};

int main() {
    Solution s;

    vector<int> A1 = {34, 23, 1, 24, 75, 33, 54, 8};
    assert(s.twoSumLessThanK(A1, 60) == 58);

    vector<int> A2 = {10, 20, 30};
    assert(s.twoSumLessThanK(A2, 15) == -1);

    vector<int> A3 = {};
    assert(s.twoSumLessThanK(A3, 1) == -1);

    vector<int> A4 = {90, 85, 75, 60, 120, 150, 125};
    assert(s.twoSumLessThanK(A4, 220) == 215);

}