/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * Input: "()"
 * Output: true
 * Example 2:
 * 
 * Input: "()[]{}"
 * Output: true
 * Example 3:
 * 
 * Input: "(]"
 * Output: false
 * Example 4:
 * 
 * Input: "([)]"
 * Output: false
 * Example 5:
 * 
 * Input: "{[]}"
 * Output: true
 */

#include <stdbool.h>
#include "include/utils.h"

int main()
{
}

bool isValid(char *s)
{
    int l = i_string_len(s);
    if (l == 0)
    {
        return true;
    }

    char p[l];
    int i = -1;

    while (*s)
    {
        switch (*s)
        {
        case '(':
        case '{':
        case '[':
            i++;
            p[i] = *s;
            break;
        case ')':
            if (i < 0 || p[i] != '(')
            {
                return false;
            }
            i--;
            break;
        case '}':
            if (i < 0 || p[i] != '{')
            {
                return false;
            }
            i--;
            break;
        case ']':
            if (i < 0 || p[i] != '[')
            {
                return false;
            }
            i--;
            break;
        default:
            return false;
            break;
        }
        s++;
    }
    if (i != -1)
    {
        return false;
    }

    return true;
}