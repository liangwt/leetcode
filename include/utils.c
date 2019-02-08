#include "utils.h"
#include <stdio.h>

inline int i_array_len(int *array)
{
    int l = 0;
    while (array)
    {
        l++;
        array++;
    }
    return l;
}

int i_string_len(char *s)
{
    int l = 0;
    while (s)
    {
        l++;
        s++;
    }
    return l;
}

char *i_itoa(int v, char *str)
{
    int i;
    char tmp[33];
    char *tp = tmp;

    while (v || tp == tmp)
    {
        i = v % 10;
        *tp++ = i + '0';
        v = v / 10;
    }
    char *sp = str;
    while (tp > tmp)
        *sp++ = *--tp;

    *sp++ = '\0';
    
    return str;
}