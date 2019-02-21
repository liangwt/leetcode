/**
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * Example 2:
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 *              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <string.h>
#include <stdio.h>
#include "include/utils.h"

int lengthOfLongestSubstring(char *s);

int main()
{
    char s[] = "abcabcbb";
    printf("an: %d", lengthOfLongestSubstring(s));

    return 0;
}

int lengthOfLongestSubstring(char *s)
{
    // must be init with zero, otherwise wrong answer will out in some compiler
    int flag[256] = {0};
    int r = -1, l = 0, ret = 0;
    int len = strlen(s);

    while (l < len)
    {
        if (r + 1 < len && flag[s[r + 1]] == 0)
        {
            flag[s[r + 1]]++;
            r++;
        }
        else
        {
            flag[s[l]]--;
            l++;
        }

        ret = I_MAX(ret, r - l + 1);
    }

    return ret;
}