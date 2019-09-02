/**
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * [[0,0,0],
 *  [0,1,0],
 *  [0,0,0]]
 *
 * Output:
 * [[0,0,0],
 *  [0,1,0],
 *  [0,0,0]]
 * Example 2:
 *
 * Input:
 * [[0,0,0],
 *  [0,1,0],
 *  [1,1,1]]
 *
 * Output:
 * [[0,0,0],
 *  [0,1,0],
 *  [1,2,1]]
 *
 *
 * Note:
 *
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 */

/**
 * 第一遍扫描全部元素，把零加入到队列中，同时创建一个新的二维数组作为返回值，把其中非零对应位置INT_MAX
 *
 * 从队列弹出元素，对其位置的比前后左右，如果大于当前位置的值加1则更新，并加入到队列
 * 实际上就是当某个元素值距离值被更新了，如果新值让周围元素距离变小了就得把周围元素的也更新遍
 *
 */

#include <vector>
#include <queue>

using namespace std;

int mx[] = {0, 1, 0, -1};
int my[] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        queue<pair<int, int>> q;
        vector<vector<int>> ret(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    ret[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();

            // 对比前后左右，如果大于当前位置加1则更新，并加入到队列
            for (int i = 0; i < 4; i++) {
                int distance = ret[t.first][t.second];

                int col = t.second + mx[i];
                int row = t.first + my[i];

                if (row >= 0 && row < ret.size() && col >= 0 && col < ret[0].size()) {
                    if (ret[row][col] > distance + 1) {
                        ret[row][col] = distance + 1;
                        q.push({row, col});
                    }
                }
            }

        }

        return ret;
    }
};

int main() {
    Solution s;

    vector<vector<int>> m1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    vector<vector<int>> r1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    assert(s.updateMatrix(m1) == r1);

    vector<vector<int>> m2 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
    };
    vector<vector<int>> r2 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 2, 1},
    };
    assert(s.updateMatrix(m2) == r2);

    return 0;
}
