#include <stdio.h>
#include <stdlib.h>

char *countAndSay(int n);
void expend(char *s, size_t max_len, char *ret_value);
int i_strlen(char *s);

int main()
{
    printf("an: %s", countAndSay(4));
}

char *countAndSay(int n)
{
    char *ret = "1";

    for (int i = 1; i <= n; i++)
    {
        int l = i_strlen(ret);
        char *r = malloc(sizeof(char) * 2 * l);
        expend(ret, l, r);
    }

    return ret;
}

void expend(char *s, size_t max_len, char *ret_value)
{
    int j = 0, i = 0;
    while (i < max_len)
    {
        if (s[i] == '1')
        {
            if (s[i + 1] == '1')
            {
                ret_value[j] = '2';
                ret_value[j + 1] = '1';
                j += 2;
                i++;
            }
            else
            {
                ret_value[j] = '1';
                j++;
            }
        }
        if (s[i] == '2')
        {
            ret_value[j] = '1';
            ret_value[j] = '2';
            j += 2;
        }
        i++;
    }

    ret_value[j] = '\0';
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