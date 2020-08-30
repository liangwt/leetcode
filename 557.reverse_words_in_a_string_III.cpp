#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.size(), i = 0, j = 0;
        string ans;

        while (i < len)
        {
            if (i == len - 1 || s[i + 1] == ' ')
            {
                int k = i;
                while (k >= 0 && s[k] != ' ')
                {
                    ans.push_back(s[k]);
                    k--;
                }
            }
            else if (s[i] == ' ')
            {
                ans.push_back(' ');
            }

            i++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    
    assert(s.reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");
    assert(s.reverseWords("") == "");
}