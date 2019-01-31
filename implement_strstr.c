#include <stdio.h>

int strStr(char *haystack, char *needle);
int i_strlen(char *s);

int main()
{
    printf("an: %d", strStr("mississippi", "issip"));

    return 0;
}

int strStr(char *haystack, char *needle)
{
    int I = i_strlen(haystack);
    int J = i_strlen(needle);
    int i = 0, j = 0;
    while (i < I && j < J)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == J)
    {
        return i - J;
    }

    return -1;
}

inline int i_strlen(char *s)
{
    int l = 0;
    while (*s)
    {
        l++;
        s++;
    }
    return l;
}