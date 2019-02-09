/**
 * Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
 * Example 1:
 * 
 * Input: 00000000000000000000000000001011
 * Output: 3
 * Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
 * Example 2:
 * 
 * Input: 00000000000000000000000010000000
 * Output: 1
 * Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
 * Example 3:
 * 
 * Input: 11111111111111111111111111111101
 * Output: 31
 * Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 *  
 * 
 * Note:
 * 
 * Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above the input represents the signed integer -3.
 *  
 * 
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 */
#include <inttypes.h>
#include <stdio.h>

uint8_t TABLE[] = {
    0, // 0000 => 0
    1, // 0001 => 1
    1, // 0010 => 2
    2, // 0011 => 3
    1, // 0100 => 4
    2, // 0101 => 5
    2, // 0110 => 6
    3, // 0111 => 7
    1, // 1000 => 8
    2, // 1001 => 9
    2, // 1010 => 10
    3, // 1011 => 11
    2, // 1100 => 12
    3, // 1101 => 13
    3, // 1110 => 14
    4, // 1111 => 15
};

int hammingWeight(uint32_t n);

int main()
{
    int l = hammingWeight(122);
    printf("an: %d\n", l);
}

int hammingWeight(uint32_t n)
{
    int l = 0;
    while (n != 0)
    {
        l += TABLE[n & 15];
        n = n >> 4;
    }

    return l;
}
