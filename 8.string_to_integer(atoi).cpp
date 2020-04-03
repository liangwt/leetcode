#include <string>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int ans = 0;
        int flag = 1;
        bool start = false;

        for (const auto &ss : str)
        {
            // 没开始的时候，仅允许 空格、-、+、数字
            if (!start && ss != ' ' && ss != '-' && ss != '+' && (ss < '0' || ss > '9'))
            {
                break;
            }

            // 没开始对空跳过
            if (!start && ss == ' ')
            {
                continue;
            }

            // 没开始，匹配-，仅第一次匹配，后续不会再匹配了
            if (!start && ss == '-')
            {
                flag = -1;
                start = true;
                continue;
            }

            // 没开始，匹配+，仅第一次匹配，后续不会再匹配了
            if (!start && ss == '+')
            {
                flag = 1;
                start = true;
                continue;
            }

            // 开始之后，非数字会被跳过
            if (start && (ss < '0' || ss > '9'))
            {
                break;
            }

            start = true;

            // 这时ss仅可能是数字了

            int n = ss - '0';

            // 需要计算有没有溢出
            if (flag == -1 && ans < (INT_MIN + n) / 10)
            {
                return INT_MIN;
            }

            // 需要计算有没有溢出
            if (flag == 1 && ans > (INT_MAX - n) / 10)
            {
                return INT_MAX;
            }

            ans = ans * 10 + flag * (ss - '0');
        }

        return ans;
    }
};

int main()
{
    Solution s;

    assert(s.myAtoi("  42") == 42);
    assert(s.myAtoi("   -42") == -42);
    assert(s.myAtoi("4193 with words") == 4193);
    assert(s.myAtoi("words and 987") == 0);
    assert(s.myAtoi("-91283472332") == -2147483648);
    assert(s.myAtoi("+11") == 11);
    assert(s.myAtoi("+1 1") == 1);
}