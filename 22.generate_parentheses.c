/**
 * Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
*/

/**
 *
 * 递归思路：
 * 左括号和右括号一定为n个，所以两个变量left和right来记录剩余括号数
 * 维护一个temp作为在递归过程中的中间字符串
 * 当满足left == 0 && right == 0时说明全部括号已经用完，所以此时将temp加入到最终结果res中
 * 在递归过程中会有如下几种状态
 *  1. left > right:            说明此时temp右括号比左括号多，此时temp已经不满足闭合要求，直接返回
 *  2. left == 0 && right == 0: 全部括号已经用完，所以此时将temp加入到最终结果res中
 *  3. left > 0:                左括号还有剩余，在temp后面拼接一个'(' 同时 left -= 1，进入下一层递归
 *  4. right > 0:               左括号还有剩余，在temp后面拼接一个'(' 同时 left -= 1，进入下一层递归
 *
 * 当n=3时的递归树
 *
 *                                                     ""
 *                                                  l=3,r=3
 *
 *                                              '('                   ')'
 *                                           l=2,r=3                l=3,r=2,不合法
 *
 *                              '(('                       '()'
 *                             l=1,r=3                    l=2,r=2
 *
 *                      '((('         '(()'        '()('            '())'
 *                    l=0,r=3        l=1,r=2      l=1,r=2         l=2,r=1,X
 *
 *              '((()'        '(()('   '(())'    '()(('   '()()'
 *             l=0,r=2       l=0,r=1   l=1,r=1   l=0,r=2  l=1,r=1
 *
 *          ....
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **generateParenthesis(int n, int *returnSize);

int main() {
    int returnSize = 0;
    char **res = generateParenthesis(8, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", res[i]);
        free(res[i]);
    }
    free(res);
}


void _generateParenthesis(char **res, int *returnSize, int n, int left, int right, char *tmp) {
    if (left > right) {
        return;
    }

    if (left == 0 && right == 0) {
        res[*returnSize] = strdup(tmp);
        ++(*returnSize);
    } else {
        if (left > 0) {
            // 需要单独维护一个t栈变量，如果直接把tmp递归会导致tmp在递归的过程中被改变
            // 此处需要深入理解字符串在参数中传递的是指针的值，所以在函数内对字符串参数的改变会影响调用方
            // @link https://www.zhihu.com/question/26117197
            char t[2 * n + 1];
            strcpy(t, tmp);
            strcat(t, "(");
            int l = left - 1;
            _generateParenthesis(res, returnSize, n, l, right, t);
        }

        if (right > 0) {
            char t[2 * n + 1];
            strcpy(t, tmp);
            strcat(t, ")");
            int r = right - 1;
            _generateParenthesis(res, returnSize, n, left, r, t);
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize) {
    char **res = malloc(10000 * sizeof(char *));
    char *tmp = malloc(sizeof(char) * 2 * n + 1);
    int left = n, right = n;

    *returnSize = 0;
    tmp[0] = '\0';

    _generateParenthesis(res, returnSize, n, left, right, tmp);
    free(tmp);

    return res;
}

