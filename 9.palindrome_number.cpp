#include <assert.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        long t1 = x, t2 = 0;

        while (t1 != 0)
        {
            t2 = t2 * 10 + (t1 % 10);
            t1 = t1 / 10;
        }

        return t2 == x;
    }
};

int main()
{
    Solution s;

    assert(s.isPalindrome(121) == true);
    assert(s.isPalindrome(2147483647) == false);
}