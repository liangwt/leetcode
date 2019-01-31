#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int myAtoi(char *str);
bool is_numeric(char s);
int char_to_int(char s);

int main()
{
    printf("an: %d\n", myAtoi("-2147483648"));
}

int myAtoi(char *str)
{
    int sign_flag = 0;
    int result = 0;
    while (*str)
    {
        if (*str == ' ')
        {
            if (sign_flag != 0)
            {
                break;
            }
            str++;
            continue;
        }

        if (!is_numeric(*str))
        {
            if (sign_flag != 0)
            {
                break;
            }
            if (*str == '+')
            {
                sign_flag = 1;
            }
            else if (*str == '-')
            {
                sign_flag = -1;
            }
            else
            {
                break;
            }

            str++;
            continue;
        }

        if (sign_flag == 0)
        {
            sign_flag = 1;
        }

        if (sign_flag == -1 && sign_flag * result <= (INT_MIN + char_to_int(*str)) / 10.0)
        {
            return INT_MIN;
        }

        if (sign_flag == 1 && result >= (INT_MAX - char_to_int(*str)) / 10.0)
        {
            return INT_MAX;
        }

        result = result * 10 + char_to_int(*str);

        str++;
    }

    return result * sign_flag;
}

bool is_numeric(char s)
{
    if (s >= '0' && s <= '9')
    {
        return true;
    }
    return false;
}

int char_to_int(char s)
{
    return s - '0';
}