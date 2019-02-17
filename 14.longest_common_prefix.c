/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * Example 2:
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main()
{
    char *strs[7] = {
        "a"};

    char *r = longestCommonPrefix(strs, 1);
    printf("an: %s\n", r);
    free(r);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0 || strlen(strs[0]) == 0)
    {
        return "";
    }
    int i = 0;
    char *r = malloc(sizeof(char) * (strlen(strs[0]) + 1));

    for (i = 0; i < strlen(strs[0]); i++)
    {
        for (int j = 0; j < strsSize; j++)
        {
            if (strs[j][i] == strs[0][i])
            {
                r[i] = strs[0][i];
            }
            else
            {
                r[i] = '\0';
                return r;
            }
        }
    }
    
    r[i] = '\0';
    return r;
}