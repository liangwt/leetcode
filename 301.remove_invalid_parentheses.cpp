/**
 * Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Example 1:
 *
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * Example 2:
 *
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * Example 3:
 *
 * Input: ")("
 * Output: [""]
 */

#include <vector>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> set;
        helper(s, set);
        return {};
    }

    void helper(string s, unordered_set<string> &set) {
        stack<char> stk;
        vector<int> loc;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            }
            if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                    loc.push_back(i);
                } else {
                    for (int j = 0; j < loc.size(); j++) {
                        string cs = s;
                        cs.erase(s.begin() + loc[j]);
                        helper(cs, set);
                    }
                }
            }
        }

        if (!stk.empty()) {
            auto i = s.find_last_of('(');
            s.erase(i);
        }

        set.insert(s);
    }


};

int main() {
    Solution s;

    assert(s.removeInvalidParentheses("()())()") == vector<string>({"()()()", "(())()"}));
    assert(s.removeInvalidParentheses("(a)())()") == vector<string>({"(a)()()", "(a())()"}));
    assert(s.removeInvalidParentheses(")(") == vector<string>({""}));

    return 0;
}