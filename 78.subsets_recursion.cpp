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
 * 对于nums中的数都有选或者不选两种选择，所以从第一个数字到最后一个构成了一棵树
 *
 *                        []
 *                   /         \
 *                  /           \
 *                 /             \
 *              1                []
 *           /    \           /     \
 *          /      \         /       \
 *       [2]       []      [2]      []
 *      /   \     /  \    /   \     / \
 *   [3]    []  [3]  []  [3]  []  [3] []
 *
 *
 *  深度递归，跟节点到叶子节点到路径就构成了最终结果
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> pre = {};
        _help(nums, 0, pre, result);
        return result;
    }

    void _help(vector<int> &nums, int idx, vector<int> &pre, vector<vector<int>> &result) {
        if (idx >= nums.size()) {
            result.push_back(pre);

            return;
        }

        _help(nums, idx + 1, pre, result);

        pre.push_back(nums[idx]);
        _help(nums, idx + 1, pre, result);
        pre.pop_back();

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
        {},
        {3},
        {1},
        {2},
        {1, 2, 3},
        {1, 3},
        {2, 3},
        {1, 2},
    };

    assert(equal(s.subsets(n1), r1));

    vector<int> n2 = {2, 4, 3, 5};
    vector<vector<int>> r2 = {
        {},
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
    };
    assert(equal(s.subsets(n1), r1));

    return 0;
}