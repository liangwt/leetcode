#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool isPalindrome(char *s);
bool is_alphanumeric(char s);
char i_upper_str(char s);
int  i_strlen(char *s);

int main()
{
    assert(isPalindrome("A man, a plan, a canal: Panama"));
    assert(!isPalindrome("race a car"));
    assert(isPalindrome(""));
    assert(!isPalindrome("0P"));
}

bool isPalindrome(char *s)
{
    int l = i_strlen(s);

    int i = 0;
    int j = l-1;
    while (i < j)
    {
        if (!is_alphanumeric(s[i]))
        {
            i++;
            continue;
        }

        if (!is_alphanumeric(s[j]))
        {
            j--;
            continue;
        }

        if (i_upper_str(s[i]) != i_upper_str(s[j]))
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

bool is_alphanumeric(char s)
{
    if (s >= '0' && s <= '9')
    {
        return true;
    }
    if (s >= 'A' && s <= 'Z')
    {
        return true;
    }
    if (s >= 'a' && s <= 'z')
    {
        return true;
    }
    return false;
}

char i_upper_str(char s)
{
    if (s >= 'a' && s <= 'z')
    {
        return s - ('a' - 'A');
    }

    return s;
}

int i_strlen(char *s)
{
    int i = 0;
    while (*s)
    {
        i++;
        s++;
    }
    return i;
}