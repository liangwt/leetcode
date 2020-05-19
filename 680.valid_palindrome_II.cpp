#include <string>

using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        string::iterator begin = s.begin();
        string::iterator end = s.end() - 1;

        while (begin <= end)
        {
            if (*begin == *end)
            {
                begin++;
                end--;
            }
            else
            {
                return valid(begin + 1, end) || valid(begin, end - 1);
            }
        }

        return true;
    }

    bool valid(string::iterator begin, string::iterator end)
    {
        while (begin <= end)
        {
            if (*begin == *end)
            {
                begin++;
                end--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    assert(s.validPalindrome("aba"));
    assert(s.validPalindrome("abca"));
}