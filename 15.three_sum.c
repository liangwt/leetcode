/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */
#include <stdio.h>
#include <stdlib.h>
int c(const void *elem1, const void *elem2);
int **threeSum(int *nums, int numsSize, int *returnSize);

int main(int argc, char *argv[])
{
    // -4 3 2 2 2 2 1
    //  x   j     k
    int nums[] = {0, 0, 0};
    int returnSize;
    int **r = threeSum(nums, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", r[i][j]);
        }
        free(r[i]);
        printf("\n");
    }
    free(r);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    int **r = malloc(sizeof(int **) * 10000);
    qsort(nums, numsSize, sizeof(int), c);

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
            break;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int t = 0 - nums[i];
        int j = i + 1;
        int k = numsSize - 1;
        while (j < numsSize && j < k)
        {
            if (nums[j] + nums[k] == t)
            {
                int *s = malloc(sizeof(int) * 3);
                s[0] = nums[i];
                s[1] = nums[j];
                s[2] = nums[k];
                r[(*returnSize)] = s;
                (*returnSize)++;
                while (j < numsSize - 1 && nums[j] == nums[j + 1])
                    j++;
                while (k > 1 && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
                continue;
            }
            if (nums[j] + nums[k] > t)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return r;
}

int c(const void *elem1, const void *elem2)
{
    int f = *((int *)elem1);
    int s = *((int *)elem2);
    if (f > s)
        return 1;
    if (f < s)
        return -1;
    return 0;
}