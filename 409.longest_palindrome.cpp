#include <string>
#include <unordered_map>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int table[58];
        memset(table, 0, sizeof(table));

        for (auto ss : s)
        {
            table[ss - 'A']++;
        }

        int result = 0;
        bool special = false;

        for (int i = 0; i < 58; i++)
        {
            int len = table[i];

            if (len % 2 == 0)
            {
                result += len;
            }
            else
            {
                result += max(len - 1, 0);
            }

            if (len % 2 != 0 && !special)
            {
                special = true;
            }
        }

        return result + special;
    }
};

int main()
{
    Solution s;
    assert(s.longestPalindrome("") == 0);
    assert(s.longestPalindrome("aaa") == 3);
    assert(s.longestPalindrome("aba") == 3);
    assert(s.longestPalindrome("abab") == 4);
    assert(s.longestPalindrome("bananas") == 5);
    assert(s.longestPalindrome("abccccdd") == 7);
}