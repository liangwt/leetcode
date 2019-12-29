/**
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int **permute(int *nums, int numsSize, int *returnSize);

void _permute(int *nums, int numsSize, int *returnSize, int **ret, int *temp, int tempSize, bool *visited);

int main() {
    int a[3] = {1, 2, 3};
    int *nums = a;
    int returnSize = 0;

    int **ret = permute(nums, 3, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d", ret[i][j]);
        }
        printf("\n");
    }

    free(ret);
}

/**
 *
 * 深度优先递归（dfs）的方式：
 *
 * 对于三个数字1、2、3
 *
 * 使用一个临时数组temp存取每个组合的中间状态
 * 加入到最后结果到数组ret的条件：temp的长度 == 3
 *
 * 每一轮递归都选择一个未使用过的数字加入到临时数组temp中
 * 所以需要使用visited来维护一个访问记录，他是维护在每一层递归栈的
 *
 * 所形成的递归数如下：
 *
 *                                       []
 *                [1]                   [2]                     [3]                visited 分别为[1]、[2]、[3]
 *         [1,2]     [1,3]       [2,1]      [2,3]        [3,1]        [3,2]        visited 分别为[1,2] [1,3] [2,1] [2,3] [3,1] [3,2]
 *    [1,2,3]  x  [1,3,2] x  [2,1,3]  x  [2,3,1] x  [3,1,2]  x   [3,2,1]   x
 *
 * @param nums
 * @param numsSize
 * @param returnSize
 * @return
 */
int **permute(int *nums, int numsSize, int *returnSize) {

    int **ret = malloc(sizeof(int *) * 10000);

    int *temp = malloc(sizeof(int) * numsSize);

    bool *visited = malloc(sizeof(bool) * numsSize);
    memset(visited, false, sizeof(bool) * numsSize);

    int tempSize = 0;

    _permute(nums, numsSize, returnSize, ret, temp, tempSize, visited);

    return ret;
}

void _permute(int *nums, int numsSize, int *returnSize, int **ret, int *temp, int tempSize, bool *visited) {
    // 当临时数组满足需求了，加入到最后到返回集中
    if (tempSize == numsSize) {
        int *t = malloc(sizeof(int) * numsSize);
        memcpy(t, temp, sizeof(int) * numsSize);
        ret[*returnSize] = t;
        (*returnSize)++;
        return;
    }

    // 深度优先遍历（dfs）
    for (int i = 0; i < numsSize; ++i) {
        if (!visited[i]) {

            // visited变量不能被下层修改，所以需要复制
            bool *v = malloc(sizeof(bool) * numsSize);
            memcpy(v, visited, sizeof(bool) * numsSize);

            // 对访问过的进行标记
            v[i] = true;

            // 添加到临时数组中
            temp[tempSize] = nums[i];
            _permute(nums, numsSize, returnSize, ret, temp, tempSize + 1, v);

            // 不要忘记释放
            free(v);
        }
    }
}



