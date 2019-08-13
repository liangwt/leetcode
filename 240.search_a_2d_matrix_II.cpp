/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * Example:
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 */

/**
 * 从整个矩阵左下角开始：
 *   1. 如果往右移动则数值在增大
 *   2. 如果往上移动则数值在减小
 * 
 * 于是从左下开始与目标值对比，如果比目标值大则往上移动；如果比目标值小则往右移动。
 * 当超出右边界(y >= coloumn)或者上边界(x < 0)的时候，则说明目标值不存在
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
        {
            return false;
        }

        pair<int, int> location = {matrix.size() - 1, 0};

        while (location.first >= 0 && location.second < matrix[0].size())
        {
            int cur = matrix[location.first][location.second];

            if (cur == target)
            {
                return true;
            }

            if (cur < target && location.second < matrix[0].size())
            {
                location.second++;
            }
            else
            {
                location.first--;
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    int target = 20;

    Solution s;
    auto r = s.searchMatrix(matrix, target);
    cout << r << endl;
    return 0;
}