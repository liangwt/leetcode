#include <vector>
#include <assert.h>

#include <iostream>

using namespace std;

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int N = 8, i = 0, j = 0;

        // location the R
        for (int ii = 0; ii < N; ++ii)
        {
            for (int jj = 0; jj < N; ++jj)
            {
                if (board[ii][jj] == 'R')
                {
                    i = ii;
                    j = jj;
                    goto CAL;
                }
            }
        }

    CAL:
        // cal the num
        int ans = 0;
        for (int ii = i - 1; ii >= 0; --ii)
        {
            if (board[ii][j] == 'B')
            {
                break;
            }

            if (board[ii][j] == 'p')
            {
                ans++;
                break;
            }
        }

        for (int ii = i + 1; ii < N; ++ii)
        {
            if (board[ii][j] == 'B')
            {
                break;
            }

            if (board[ii][j] == 'p')
            {
                ans++;
                break;
            }
        }

        for (int jj = j - 1; jj >= 0; --jj)
        {
            if (board[i][jj] == 'B')
            {
                break;
            }

            if (board[i][jj] == 'p')
            {
                ans++;
                break;
            }
        }

        for (int jj = j + 1; jj < N; ++jj)
        {
            if (board[i][jj] == 'B')
            {
                break;
            }

            if (board[i][jj] == 'p')
            {
                ans++;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> b1 = {{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', 'R', '.', '.', '.', 'p'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}};
    assert(s.numRookCaptures(b1) == 3);

    vector<vector<char>> b2 = {{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'}, {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'}, {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'}, {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'}, {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}};
    assert(s.numRookCaptures(b2) == 0);

    vector<vector<char>> b3 = {{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'p', 'p', '.', 'R', '.', 'p', 'B', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'B', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}};
    assert(s.numRookCaptures(b3) == 3);
}