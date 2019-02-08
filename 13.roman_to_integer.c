/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * Input: "III"
 * Output: 3
 * Example 2:
 * 
 * Input: "IV"
 * Output: 4
 * Example 3:
 * 
 * Input: "IX"
 * Output: 9
 * Example 4:
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * Example 5:
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */
#include <stdio.h>

#define S_I 'I'
#define S_V 'V'
#define S_X 'X'
#define S_L 'L'
#define S_C 'C'
#define S_D 'D'
#define S_M 'M'

int romanToInt(char *s);
int i_string_len(char *s);

int main()
{
    printf("an: %d\n", romanToInt("III"));
}

int i_string_len(char *s)
{
    int l = 0;
    while (*s)
    {

        l++;
        s++;
    }
    return l;
}

int romanToInt(char *s)
{
    int l = i_string_len(s),
        i = 0,
        t = 0,
        r = 0;

    while (i < l)
    {
        switch (s[i])
        {
        case S_I:
            if (s[i + 1] == S_V)
            {
                t = 4;
                i++;
            }
            else if (s[i + 1] == S_X)
            {
                t = 9;
                i++;
            }
            else
            {
                t = 1;
            }
            break;
        case S_V:
            t = 5;
            break;
        case S_X:
            if (s[i + 1] == S_L)
            {
                t = 40;
                i++;
            }
            else if (s[i + 1] == S_C)
            {
                t = 90;
                i++;
            }
            else
            {
                t = 10;
            }
            break;
        case S_L:
            t = 50;
            break;
        case S_C:
            if (s[i + 1] == S_D)
            {
                t = 400;
                i++;
            }
            else if (s[i + 1] == S_M)
            {
                t = 900;
                i++;
            }
            else
            {
                t = 100;
            }
            break;
        case S_D:
            t = 500;
            break;
        case S_M:
            t = 1000;
            break;
        }
        r += t;
        i++;
    }

    return r;
}