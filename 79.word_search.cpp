/*
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * Example:
 *
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 */


/**
 * 从二维数组中选择一个和字符串开头相同的位置，然后遍历该位置的上下左右，形成递归
 *
 * 技巧：
 *  使用visited来记录已经遍历过的位置，可以传递visited的引用，在完成当前位置的判断的时候再恢复当前位置的值
 *
 */

#include <vector>
#include <string>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
    bool exist(vector<vector<char>> &board, const string &word) {
        vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        int word_size = (int) word.size();
        int str_idx = 0;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[str_idx]) {
                    if (str_idx + 1 >= word_size) {
                        return true;
                    }

                    if (_helper(board, word_size, word, visited, i, j, str_idx + 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool
    _helper(vector<vector<char>> &board, int word_size, const string &word, vector<vector<bool>> &visited, int x, int y,
            int str_idx) {

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()) {
                if (!visited[xx][yy] && board[xx][yy] == word[str_idx]) {
                    if (str_idx + 1 >= word_size) {
                        return true;
                    }

                    if (_helper(board, word_size, word, visited, xx, yy, str_idx + 1)) {
                        return true;
                    }
                }
            }
        }

        visited[x][y] = false;

        return false;
    }
};

int main() {
    Solution s;

    vector<vector<char>> b1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    assert(s.exist(b1, "ABCCED"));
    assert(s.exist(b1, "SEE"));
    assert(!s.exist(b1, "ABCB"));

    vector<vector<char>> b2 = {
        {'a'},
    };

    vector<vector<char>> b3 = {
        {'a', 'b'},
        {'c', 'd'},
    };
    assert(!s.exist(b3, "abcd"));

    vector<vector<char>> b4 = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'},
    };
    assert(s.exist(b4, "AAB"));

    return 0;
}