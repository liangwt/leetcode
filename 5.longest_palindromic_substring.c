/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 * 
 * Input: "cbbd"
 * Output: "bb"
 */

#include <stdio.h>
#include <string.h>

char *longestPalindrome(char *s);

int main()
{
    char s[] = "looooooooooooooool";
    printf("an: %s", longestPalindrome(s));
}

/**
 * 挨个遍历字符串，从当前字符向两边扩散来判断是否满足回文要求
 * 
 * 第一种：
 * 对于奇数回文，当前字符为中间位置
 * 对于偶数回文，当前字符到下一个不字符为中间位置
 * 
 * 第二种：
 * 以某一个字符开始，到下一个不重复字符都为中间值，这种条件下不需要关心奇偶性
 * 如 lol       匹配到o时 直接向两边扩散即可
 * 如 lool      匹配到第一个o时，会以oo为中心向两边扩散
 * 如 loool     匹配到第一个o时，会以ooo为中心向两边扩散
 */
char *longestPalindrome(char *s)
{
    int len = strlen(s),
        start = 0,
        maxLen = 1,
        i = 0;

    while (i < len)
    {
        int left = i, right = i;

        // 向右找不相同的字符
        while (right < len - 1 && s[right + 1] == s[right])
            right++;

        // 重复字符不需要判断直接移动i到下一个不重复字符
        i = right + 1;

        // 从left..right向两边扩散
        while (right < len && left >= 0)
        {
            if (s[left] != s[right])
            {
                break;
            }
            left--;
            right++;
        }

        // 向两边扩散结果，此时 s[left] != s[right]
        // 更新最终结果
        if (maxLen < right - left - 1)
        {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }

    // 输出结果
    // 注意strncpy不会在dst上加'\0' 所以需要手动补
    char p[maxLen + 1];
    strncpy(p, s + start, maxLen);
    p[maxLen] = '\0';
    char *r = strdup(p);

    return r;
}