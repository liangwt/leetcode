/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 *
 * Example 1:
 * 
 * Input: 
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output: 
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 * Example 2:
 * 
 * Input: 
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output: 
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 * Follow up:
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
void setZeroes(int **matrix, int matrixRowSize, int matrixColSize);

int main(int argc, char *argv[])
{
    int matrixRowSize = 3;
    int matrixColSize = 3;

    int **matrix = malloc(sizeof(int **) * matrixRowSize * matrixColSize);

    matrix[0] = (int[3]){1, 1, 1};
    matrix[1] = (int[3]){1, 0, 1};
    matrix[2] = (int[3]){1, 1, 1};

    setZeroes(matrix, matrixRowSize, matrixColSize);

    for (int i = 0; i < matrixColSize; i++)
    {
        for (int j = 0; j < matrixRowSize; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    free(matrix);
}
/**
 *分别维护m和n的两个数组保存对应的行和列是不是需要置 0
 * 
 * 对于
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * 
 * 得
 *  [1, 0, 1]
 * [
 * 1,
 * 0,
 * 1
 * ] 
 * 
 */
void setZeroes(int **matrix, int matrixRowSize, int matrixColSize)
{
    bool row_zeroes[matrixRowSize];
    bool col_zeroes[matrixColSize];

    for (int i = 0; i < matrixRowSize; i++)
    {
        row_zeroes[i] = false;
    }

    for (int j = 0; j < matrixColSize; j++)
    {
        col_zeroes[j] = false;
    }

    for (int i = 0; i < matrixRowSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            if (matrix[i][j] == 0)
            {
                row_zeroes[i] = true;
                col_zeroes[j] = true;
            }
        }
    }

    for (int i = 0; i < matrixRowSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            if (row_zeroes[i] || col_zeroes[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}