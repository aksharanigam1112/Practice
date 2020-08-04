#include<iostream>
using namespace std;

bool rowSearch(char board[9][9], int row, int col, int val)
{
    for(int i=0;i<9;i++)
    {
        if(i!=col && board[row][i]==val)
            return false;
    }
    return true;
}
    
bool colSearch(char board[9][9], int row, int col, int val)
{
    for(int i=0;i<9;i++)
    {
        if(i!=row && board[i][col]==val)
            return false;
    }
    return true;
}
    
bool gridSearch(char board[9][9], int row, int col, int val)
{
    int GR = (row/3)*3 , GC = (col/3)*3;
        
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i+GR!=row && j+GC!=col && board[i+GR][j+GC] == val)
                return false;
        }
    }
    return true;
}

bool isValid(char board[9][9], int row, int col, int val)
{
    if(rowSearch(board,row,col,val) && colSearch(board,row,col,val) && gridSearch(board,row,col,val))
        return true;
    else
        return false;
}
    
bool isValidSudoku(char board[9][9]) 
{
    int fills = 0 , valid = 0;
        
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                fills++;
                if(isValid(board,i,j,board[i][j]))
                    valid++;
            }
        }
    }
    if(valid == fills)
        return true;
    else
        return false;
}
    
int main()
{
    char arr[9][9] = {{'5','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}};
    cout<<"Is the sudoku valid : "<<(isValidSudoku(arr) ? "Yes" : "No")<<endl;
}