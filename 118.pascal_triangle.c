/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Example:
 * 
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

#include <stdlib.h>

int **generate(int numRows, int **columnSizes);

int main()
{
    int *columnSizes;
    generate(0, &columnSizes);
    return 0;
}

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int **columnSizes)
{
    if (numRows == 0)
    {
        int **r = malloc(sizeof(int *));
        *columnSizes = malloc(sizeof(int));
        (*columnSizes)[0] = 1;
        return r;
    }

    int **r = malloc(sizeof(int *) * numRows);
    *columnSizes = malloc(sizeof(int) * numRows);

    r[0] = malloc(sizeof(int));
    r[0][0] = 1;

    (*columnSizes[0]) = 1;

    for (int i = 1; i < numRows; i++)
    {
        r[i] = malloc(sizeof(int) * (i + 1));

        // [] is prior to *
        (*columnSizes)[i] = i + 1;

        // head and end of each row
        r[i][0] = 1;
        r[i][i] = 1;

        // each element except head and end
        for (int j = 1; j < i; j++)
        {
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
    }

    return r;
}