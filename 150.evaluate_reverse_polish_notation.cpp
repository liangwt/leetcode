/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Note:
 *
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
 * Example 1:
 *
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * Example 2:
 *
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * Example 3:
 *
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation:
 *   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 */

/**
 * 使用一个栈，把数字全部压入栈中
 * 当遇到计算符时，弹出栈顶的两个元素进行计算，并把计算结果加入到栈顶
 *
 * 知道遍历完数组，此时栈中只有一个元素也是最后结果
 */

#include <vector>
#include <string>
#include <stack>

#include <assert.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> sk;

        for (auto &t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                sk.push(stoi(t));
                continue;
            }

            int n1 = sk.top();
            sk.pop();
            int n2 = sk.top();
            sk.pop();

            int result;

            if (t == "+") {
                result = n2 + n1;
            } else if (t == "-") {
                result = n2 - n1;
            } else if (t == "*") {
                result = n2 * n1;
            } else {
                result = n2 / n1;
            }

            sk.push(result);
        }

        return sk.top();
    }
};

int main() {
    Solution s;

    vector<string> t1 = {"2", "1", "+", "3", "*"};
    assert(s.evalRPN(t1) == 9);

    vector<string> t2 = {"4", "13", "5", "/", "+"};
    assert(s.evalRPN(t2) == 6);

    vector<string> t3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    assert(s.evalRPN(t3) == 22);

    return 0;
}