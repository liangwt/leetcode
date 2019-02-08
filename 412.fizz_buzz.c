/**
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 *     "1",
 *     "2",
 *     "Fizz",
 *     "4",
 *     "Buzz",
 *     "Fizz",
 *     "7",
 *     "8",
 *     "Fizz",
 *     "Buzz",
 *     "11",
 *     "Fizz",
 *     "13",
 *     "14",
 *     "FizzBuzz"
 * ]
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./include/utils.h"

char **fizzBuzz(int n, int *returnSize);

int main()
{
    int returnSize;
    char **ret = fizzBuzz(20, &returnSize);
    char *t;
    for (int i = 0; i < returnSize; i++)
    {
        t = ret[i];
        while (*t)
        {
            printf("%c", *t);
            t++;
        }
        printf("\n");
        free(ret[i]);
    }
    free(ret);
    return 0;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    *returnSize = n;
    char **r = malloc(sizeof(char *) * n);
    char *t;

    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            t = malloc(sizeof(char) * 9);
            strcpy(t, "FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            t = malloc(sizeof(char) * 5);
            strcpy(t, "Fizz");
        }
        else if (i % 5 == 0)
        {
            t = malloc(sizeof(char) * 5);
            strcpy(t, "Buzz");
        }
        else
        {
            t = malloc(sizeof(char) * 33);
            i_itoa(i, t);
        }
        r[i - 1] = t;
    }
    return r;
}
