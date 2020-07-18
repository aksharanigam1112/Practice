#include<iostream>
#include<bits/stdc++.h>
#define N 9
using namespace std;


void print(int grid[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
}


bool gridSearch(int grid[N][N],int row,int col,int k)
{
    int GR = (row/3)*3 , GC = (col/3)*3;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+GR][i+GC] == k)
                return false;
        }
    }
    return true;
}

bool rowSearch(int grid[N][N],int col, int k)
{
    for(int i=0;i<N;i++)
    {
        if(grid[i][col]==k)
            return false;
    }
    return true;
}

bool colSearch(int grid[N][N],int row, int k)
{
    for(int i=0;i<N;i++)
    {
        if(grid[row][i]==k)
            return false;
    }
    return true;
}

bool isValidValue(int grid[N][N],int row,int col,int k)
{
    if(rowSearch(grid,col,k) && colSearch(grid,row,k) && gridSearch(grid,row,col,k))
        return true;
    else
        return false;
}


void sudoku(int grid[N][N],int row,int col)
{
    if(row==N)
    {
        print(grid);
        return;
    }

    if(grid[row][col]>0)
        return col+1==N ? sudoku(grid,row+1,0) : sudoku(grid,row,col+1);

    for(int i=1;i<=9;i++)
    {
        if(isValidValue(grid,row,col,i))
        {
            grid[row][col]=i;
            if(col+1==N)
                sudoku(grid,row+1,0);
            else
                sudoku(grid,row,col+1);
        }
        grid[row][col]=-1;
    }
}

int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  

    sudoku(grid,0,0);
}