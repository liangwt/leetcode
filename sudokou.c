#include <stdio.h>
#include <stdbool.h>

bool draw(char board[9][9], int boardRowSize, int boardColSize);

// 重置
void reSetNumSet(int *numSet)
{
    for (int i = 0; i < 10; i++)
    {
        numSet[i] = 0;
    }
}

int main()
{
    char board[9][9] = {
    {'.','.','4','.','.','.','6','3','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'5','.','.','.','.','.','.','9','.'},
    {'.','.','.','5','6','.','.','.','.'},
    {'4','.','3','.','.','.','.','.','1'},
    {'.','.','.','7','.','.','.','.','.'},
    {'.','.','.','5','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'}
};

    printf("%d\n", draw(board, 9, 9));
}

bool draw(char board[9][9], int boardRowSize, int boardColSize)
{
// 用来判断是否含有重复数字
    int numSet[10];
    int p;
    
    reSetNumSet(numSet);
    
    // 逐行检查
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            p = board[i][j] - '0';
            if(p == -2){
                continue;
            }
            printf("i::%d, j::%d,v::%d \n", i, j, p);
            printf("numSet[p]::%d, p::%d \n", numSet[p], p);
            if (numSet[p]>=1){
                return false;
            }
            numSet[p] ++; 
        }
        reSetNumSet(numSet);
    }
    
    reSetNumSet(numSet);
    
    // 逐列检查
    for(int i = 0; i < boardColSize; i++){
        for(int j = 0; j < boardRowSize; j++){
            p = board[j][i] - '0';
            if(p == -2){
                continue;
            }
            if (numSet[p]>=1){
                return false;
            }
            numSet[p] ++; 
        }
        reSetNumSet(numSet);
    }
    
    reSetNumSet(numSet);

    
    // 3x3子域检查
    for(int i = 0; i < boardRowSize; i = i + 3){
        for(int j = 0; j < boardColSize; j = j + 3){
            for(int k = 0; k < 9; k++){
                p = board[i+k/3][j+k%3] - '0';
                if(p == -2){
                    continue;
                }
                if (numSet[p]>=1){
                    return false;
                }
                numSet[p] ++; 
            }
            reSetNumSet(numSet);
        }
    }
    
    return true;
}