/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *countAndSay(int n);

int main()
{
    printf("an: %s\n", countAndSay(1));
    printf("an: %s\n", countAndSay(2));
    printf("an: %s\n", countAndSay(30));
}

char *countAndSay(int n)
{
    char *s = strdup("1");

    for (int i = 1; i < n; i++)
    {
        int len = strlen(s);
        char t[len * 2 + 1];
        t[0] = '\0';

        int c = 1;

        for (int j = 0; j < len; j++)
        {
            if (j + 1 < len && s[j] == s[j + 1])
            {
                c++;
            }
            else
            {
                char cc[] = {c + '0', s[j], '\0'};
                strcat(t, cc);
                c = 1;
            }
        }
        char *tt = s;
        s = strdup(t);
        free(tt);
    }

    return s;
}
