/**
 * Shuffle a set of numbers without duplicates.
 *
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int *nums;
    int size;
} Solution;

void _swap(int *nums, int i, int j);
Solution *solutionCreate(int *nums, int size);
int *solutionShuffle(Solution *obj, int *returnSize);

int main()
{
    int len;
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int *ret;
    Solution *s = solutionCreate(nums, 7);
    ret = solutionShuffle(s, &len);
    for (int i = 0; i < len; i++)
    {
        printf("an: %d\n", ret[i]);
    }
    printf("\n");
    ret = solutionShuffle(s, &len);
    for (int i = 0; i < len; i++)
    {
        printf("an: %d\n", ret[i]);
    }
}

Solution *solutionCreate(int *nums, int size)
{
    Solution *s = malloc(sizeof(Solution));
    s->nums = nums;
    s->size = size;

    return s;
}

/** Resets the array to its original configuration and return it. */
int *solutionReset(Solution *obj, int *returnSize)
{
    *returnSize = obj->size;
    return obj->nums;
}

/** Returns a random shuffling of the array. */
int *solutionShuffle(Solution *obj, int *returnSize)
{
    int *ret = malloc(sizeof(int) * obj->size);
    ret = memcpy(ret, obj->nums, sizeof(int) * obj->size);
    int t = 0;

    for (int i = 0; i < obj->size; i++)
    {
        t = i + rand() % (obj->size - i);
        _swap(ret, t, i);
    }
    *returnSize = obj->size;

    return ret;
}

void _swap(int *nums, int i, int j)
{
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void solutionFree(Solution *obj)
{
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */