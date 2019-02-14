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
 * 转化：
 * 按照股价差价构成一个新的数组，
 * 即 S[1]-S[0], S[2]-S[1], S[3]-S[2], ..., S[n-1]-S[n-2]，
 * 这样我们的问题就转变成求最大的连续子段和。
 * 
 * 状态:
 * f(j): 第j天时的最大收益
 * 
 * 边界:
 * f(0) = 0;
 * 
 * 状态转移方程:
 * f(j) = max(f(j-1)+S[j]-S[j-1], 0);
 * 
 * 最终结果:
 * max = max(f(0), f(1), f(2), ..., f(n));
 */
int maxProfit(int *prices, int pricesSize)
{
    int max = 0, local = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        local = I_MAX(local + prices[i] - prices[i - 1], 0);
        max = I_MAX(max, local);
    }

    return max;
}
