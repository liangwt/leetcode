/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

/**
 * 1. 相同的一组数异或结果为0 1^2^3^4^1^2^3^4 = 0
 * 2. 任何数与0异或结果为本身 1^0 = 1 2^0 = 2
 */
int missingNumber(int *nums, int numsSize)
{
    int t = 0;
    for (int i = 0; i < numsSize; i++)
    {
        t ^= (i + 1) ^ nums[i];
    }

    return t;
}