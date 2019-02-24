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
#include "include/utils.h"

char *longestPalindrome(char *s);

int main()
{
    char s[] = "babadada";
    printf("an: %s\n", longestPalindrome(s));
}

/**
 * (1) 对于 i >= mr:
 *   从i向两端扩张对比找回文串
 * (2) 对于 pos < i < mr:
 *   (1) p[j] < mr - i: 对称位置的j点回文串位于[-mr, mr]
 *      p[i] = p[j]
 *   (2) p[j] > mr - i: 对称位置的j点回文串超过了-mr，仅有部分位于[-mr, mr]
 *      从i+j/2开始向两边对比
 */

/**
 * 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * #  b  #  a  #  b  #  a  #  d  #  a  #  d  #  a  #  \0 
 * 
 * 
 */
char *longestPalindrome(char *s)
{
    int len = (strlen(s) + 1) * 2, t = 0;
    char A[len];
    int P[len];

    for (int i = 0; i < strlen(s); i++)
    {
        P[t] = 0;
        P[t + 1] = 0;
        A[t] = '#';
        A[t + 1] = s[i];
        t += 2;
    }

    A[t] = '#';
    P[t] = 0;
    A[t + 1] = '\0';
    P[t + 1] = 0;

    int mr = 0, pos = 0, max_len = 0, max_point = 0;
    for (int i = 0; i < len - 1; i++)
    {
        // 从i+P[i]开始往两边扩散
        // 当 i >= mr 时 P[i] = 1, 所以从 i 点向两边扩张
        // 当对称位置的j点回文串位于[-mr, mr], P[i] = P[j] 相当于从i + p[j] 开始扩张
        // 当对称位置的j点回文串超过了-mr,P[i] = mr - i 相当于从mr点向外扩张
        P[i] = i < mr ? (I_MIN(mr - i, P[2 * pos - i])) : 1;

        // A[i + P[i]] i 位置向右扩张
        // A[i - P[i]] i 位置向左扩张
        while (i + P[i] < len && i - P[i] >= 0 && A[i + P[i]] == A[i - P[i]])
            P[i]++;

        // 维护mr和pos
        if (i + P[i] - 1 > mr)
        {
            pos = i;
            mr = i + P[i] - 1;
        }

        // 维护最结果
        if (max_len < P[i])
        {
            max_point = i;
            max_len = P[i];
        }
    }

    // 输出结果
    // 注意strncpy不会在dst上加'\0' 所以需要手动补
    char p[max_len];
    strncpy(p, s + (max_point - max_len + 1) / 2, max_len - 1);
    p[max_len - 1] = '\0';
    char *r = strdup(p);

    return r;
}
