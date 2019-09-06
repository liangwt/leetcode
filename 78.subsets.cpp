/*
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */

/**
 * 初始一个空集合，遍历nums的每一个元素加入到结果的每一个集合中，如 {1, 2, 3}
 *
 * 初始
 *  [[]]
 * 第一轮
 *  [[], [1]]
 *
 * 第二轮
 *  [[], [1], [2], [1, 2]]
 *
 * 第三轮
 *  [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
 *
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;

        result.emplace_back();

        for (auto num:nums) {
            int len = (int) result.size();

            for (int j = 0; j < len; j++) {
                vector<int> t = result[j];
                t.push_back(num);

                result.push_back(t);
            }
        }
        return result;
    }
};

bool equal(vector<vector<int>> r1, vector<vector<int>> r2) {
    auto f = [](vector<int> r) {
        sort(r.begin(), r.end());
        return r;
    };

    transform(r1.begin(), r1.end(), r1.begin(), f);
    transform(r2.begin(), r2.end(), r2.begin(), f);

    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());

    return r1 == r2;
}

int main() {
    Solution s;

    vector<int> n1 = {1, 3, 2};
    vector<vector<int>> r1 = {
        {3},
        {1},
        {2},
        {1, 2, 3},
        {1, 3},
        {2, 3},
        {1, 2},
        {},
    };

    assert(equal(s.subsets(n1), r1));

    vector<int> n2 = {2, 4, 3, 5};
    vector<vector<int>> r2 = {
        {2},
        {3},
        {4},
        {5},
        {2, 3},
        {2, 4},
        {2, 5},
        {3, 4},
        {3, 5},
        {4, 5},
        {2, 3, 4},
        {2, 3, 5},
        {3, 4, 5},
        {2, 3, 4, 5},
        {},
    };
    assert(equal(s.subsets(n1), r1));

    return 0;
}