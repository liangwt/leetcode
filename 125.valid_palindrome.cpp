#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            while (i < s.size() && !isalnum(s[i]))
            {
                i++;
            }

            while (j >= 0 && !isalnum(s[j]))
            {
                j--;
            }

            if (i <= j)
            {
                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
            }
            i++;
            j--;
        }

        return true;
    }
};

int main(){
    Solution s;

    assert(s.isPalindrome("A man, a plan, a canal: Panama"));
    assert(!s.isPalindrome("race a car"));
    assert(s.isPalindrome(""));
    assert(!s.isPalindrome("0P"));
}
