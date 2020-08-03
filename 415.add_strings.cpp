#include <string>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int l1 = num1.size() - 1, l2 = num2.size() - 1;
        char overflow = 0;
        string ans;

        while (l1 >= 0 || l2 >= 0 || overflow > 0)
        {
            int a = 0, b = 0;

            if (l1 >= 0)
            {
                a = num1[l1] - '0';
            }

            if (l2 >= 0)
            {
                b = num2[l2] - '0';
            }

            char c = a + b + overflow;

            if (c >= 10)
            {
                c = c - 10;
                overflow = 1;
            }
            else
            {
                overflow = 0;
            }

            ans.push_back(c + '0');

            l1--;
            l2--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;

    assert(s.addStrings("0", "0") == "0");
    assert(s.addStrings("1", "9") == "10");
    assert(s.addStrings("1", "17") == "18");
}