/**
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 * 
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 *     ...
 * Example 1:
 * 
 * Input: "A"
 * Output: 1
 * Example 2:
 * 
 * Input: "AB"
 * Output: 28
 * Example 3:
 * 
 * Input: "ZY"
 * Output: 701
 */

/**
 * 和十进制一样，每一位代表26。
 * 
 * 所以从最低位依次往上乘26即可
 */

#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int t = 0;
        for (auto c : s)
        {
            t *= 26;
            t += (int(c) - 64);
        }

        return t;
    }
};

int main()
{
    Solution s;

    assert(s.titleToNumber("A") == 1);
    assert(s.titleToNumber("AB") == 28);
    assert(s.titleToNumber("ZY") == 701);

    return 0;
}