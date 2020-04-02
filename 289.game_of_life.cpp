#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
private:
    int x_len;
    int y_len;

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        x_len = board[0].size();
        y_len = board.size();
        auto copy_board = board;

        for (int i = 0; i < y_len; ++i)
        {
            for (int j = 0; j < x_len; ++j)
            {
                int nums = calLive(copy_board, i, j);

                if (copy_board[i][j] == 1)
                {
                    if (nums < 2)
                    {
                        board[i][j] = 0;
                    }
                    else if (nums >= 2 && nums <= 3)
                    {
                        board[i][j] = 1;
                    }
                    else
                    {
                        board[i][j] = 0;
                    }
                }
                else
                {
                    if (nums == 3)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }

    // cal the live cell beyond eight locations
    int calLive(vector<vector<int>> &board, int i, int j)
    {
        vector<pair<int, int>> dir = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1},
        };

        int nums = 0;
        for (auto [dx, dy] : dir)
        {
            int xx = j + dx;
            int yy = i + dy;
            if (xx >= 0 && xx < x_len && yy >= 0 && yy < y_len && board[yy][xx] == 1)
            {
                nums++;
            }
        }

        return nums;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> b1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    vector<vector<int>> ans1 = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 1},
        {0, 1, 0}};

    s.gameOfLife(b1);
    assert(b1 == ans1);
}