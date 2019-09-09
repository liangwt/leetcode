/**
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * Example 2:
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

/**
 * 首先按照一维数组第一个数字把输入的二维数组排序
 *
 * 再把第一个一维数组加入到最后结果之后，从第二个开始逐个遍历，
 * 如果后一个数组的开头小于最终结果的末尾则说明两者可以合并，如果不小于则作为一个新的区间加入到最终结果中
 * 以此类推，直到把二维数组里的每一对都比较过来
 *
 * 例如
 *
 * [[1,3],[2,6],[8,10],[15,18]] 排序完之后还是这个顺序
 *
 * 把第一个元素加入到最终结果为[[1,3]]
 *
 * 第一轮对比 [1,3],[2,6]
 *
 * 因为2<3，说明两者可以合并，于是把[1,3]中的3换成6得：[[1,6]]
 *
 * 第二轮对比 [1,6],[8,10]
 *
 * 因为8>6说明是一个新的区间，则单独加入到最后结果得：[[1,6],[8,10]]
 *
 * 第三轮对比 [8,10],[15,18]
 *
 * 因为15>10，所以还是一个新区间，加入到最后结果得：[[1,6],[8,10],[15,18]]
 *
 * 于是最终结果就是[[1,6],[8,10],[15,18]]
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) -> bool {
            return x[0] < y[0];
        });

        vector<vector<int>> result{intervals[0]};

        for (size_t i = 1; i < intervals.size(); i++) {
            vector<int> *last = &result.back();

            if ((*last)[1] >= intervals[i][0]) {
                (*last)[1] = max(intervals[i][1], (*last)[1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> i1 = {
        {1, 4},
        {4, 5},
    };
    assert(s.merge(i1) == vector<vector<int>>({{1, 5}}));

    vector<vector<int>> i2 = {
        {1,  3},
        {2,  6},
        {8,  10},
        {15, 18},
    };
    vector<vector<int>> r2 = {
        {1,  6},
        {8,  10},
        {15, 18},
    };
    assert(s.merge(i2) == r2);

    vector<vector<int>> i3 = {{}};
    assert(s.merge(i3) == vector<vector<int>>({{}}));
}