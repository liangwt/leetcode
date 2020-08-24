#include <string>

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string sub;
        int i = 0, len = s.size();

        while (i < len - 1)
        {
            sub.push_back(s[i]);

            int j = i + 1;
            bool flag = true;

            while (j < len)
            {
                if (sub != s.substr(j, sub.size()))
                {
                    flag = false;
                    break;
                }
                j += sub.size();
            }

            if (j == len && flag)
            {
                return true;
            }

            i++;
        }

        return false;
    }
};

int main()
{
    Solution s;
    assert(s.repeatedSubstringPattern("abab") == true);
    assert(s.repeatedSubstringPattern("aba") == false);
    assert(s.repeatedSubstringPattern("abcabcabcabc") == true);
}