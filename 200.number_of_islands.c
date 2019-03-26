/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int numIslands(char **grid, int gridRowSize, int gridColSize);

void _numIslands(char **grid, int gridRowSize, int gridColSize, bool visited[gridRowSize][gridColSize], int i, int j);

int main() {
    int gridRowSize = 4, gridColSize = 5;

    char t[][5] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };

    char **grid = malloc(sizeof(char *) * gridColSize);

    for (int i = 0; i < gridRowSize; i++) {
        grid[i] = t[i];
    }

    int num = numIslands(grid, gridRowSize, gridColSize);

    // 释放内存
    free(grid);

    printf("an: %d", num);
}

int numIslands(char **grid, int gridRowSize, int gridColSize) {
    // 返回结果
    int r = 0;

    if (gridRowSize == 0 || gridColSize == 0) {
        return r;
    }

    // 创建一个同样大小的数组来记录对应节点是否已经被访问
    bool visited[gridRowSize][gridColSize];
    memset(visited, false, sizeof(bool) * gridRowSize * gridColSize);

    for (int i = 0; i < gridRowSize; ++i) {
        for (int j = 0; j < gridColSize; ++j) {
            if (grid[i][j] != '0' && !visited[i][j]) {
                r++;
                // 寻找连接在一块所有节点
                _numIslands(grid, gridRowSize, gridColSize, visited, i, j);
            }
        }
    }

    return r;
}

/**
 * 寻找连接在一块所有节点
 * 原理就是递归遍历每一个相邻的元素，直到最终元素达到边界（value = 0）
 * 遍历的同时记录的节点位置
 * 只递归右、下不能达到要求
 *
 * @param grid
 * @param gridRowSize
 * @param gridColSize
 * @param visited
 * @param i
 * @param j
 * @return
 */
void _numIslands(char **grid, int gridRowSize, int gridColSize, bool visited[gridRowSize][gridColSize], int i, int j) {
    // 达到了grid的边界
    if (i < 0 || j < 0 || i >= gridRowSize || j >= gridColSize) {
        return;
    }

    // 达到了元素连接的边界
    if (grid[i][j] == '0' || visited[i][j]) {
        return;
    }

    // 标记此节点已经被遍历过
    visited[i][j] = true;

    // 递归遍历下方元素
    _numIslands(grid, gridRowSize, gridColSize, visited, i + 1, j);

    // 递归遍历右方元素
    _numIslands(grid, gridRowSize, gridColSize, visited, i, j + 1);

    // 递归遍历上方元素
    _numIslands(grid, gridRowSize, gridColSize, visited, i - 1, j);

    // 递归遍历左方元素
    _numIslands(grid, gridRowSize, gridColSize, visited, i, j - 1);
}

