#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sk;

        for (const auto &ss : s)
        {
            switch (ss)
            {
            case '(':
            case '{':
            case '[':
                sk.push(ss);
                break;
            case ')':
                if (sk.empty() || sk.top() != '(')
                {
                    return false;
                }
                sk.pop();
                break;
            case '}':
                if (sk.empty() || sk.top() != '{')
                {
                    return false;
                }
                sk.pop();
                break;
            case ']':
                if (sk.empty() || sk.top() != '[')
                {
                    return false;
                }
                sk.pop();
                break;
            default:
                return false;
            }
        }

        return sk.empty();
    }
};

int main()
{
    Solution s;
    assert(s.isValid("]") == false);
    assert(s.isValid("([)]") == false);
    assert(s.isValid("") == true);
    assert(s.isValid("()[]{}") == true);
}