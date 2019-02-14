/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 * Example 2:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */
#include <stdio.h>
#include <limits.h>
#include "include/utils.h"

int maxProfit(int *prices, int pricesSize);

int main()
{
    int prices1[] = {7, 1, 5, 3, 6, 4};
    printf("an: %d\n", maxProfit(prices1, 6));

    int prices2[] = {7, 6, 4, 3, 1};
    printf("an: %d\n", maxProfit(prices2, 5));
}
/**
 * 
 * 状态:
 * f(j): 第j天时的最优收益
 * 
 * 状态转移方程:
 * f(j) = max(f(j-1), S[j]-min);
 * 
 * 最终结果:
 * f(n)
 */
int maxProfit(int *prices, int pricesSize)
{
    int max = 0, min = INT_MAX;
    for (int i = 0; i < pricesSize; i++)
    {
        max = I_MAX(max, prices[i] - min);
        min = I_MIN(min, prices[i]);
    }

    return max;
}
