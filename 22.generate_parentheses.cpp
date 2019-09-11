/**
 *
 */


#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return {};
        }

        vector<string> result;
        helper(n, 0, 0, "", result);

        return result;
    }

    void helper(int n, int left_num, int right_num, string ss, vector<string> &result) {
        if (left_num > n || right_num > n || left_num < right_num) {
            return;
        }

        if (left_num == n && right_num == n) {
            result.push_back(ss);
            return;
        }

        helper(n, left_num + 1, right_num, ss + "(", result);
        helper(n, left_num, right_num + 1, ss + ")", result);
    }
};

int main() {
    Solution s;

    vector<string> r1 = {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()",
    };
    assert(s.generateParenthesis(3) == r1);

    vector<string> r2 = {};
    assert(s.generateParenthesis(0) == r2);

    vector<string> r3 = {"()"};
    assert(s.generateParenthesis(1) == r3);

    return 0;
}