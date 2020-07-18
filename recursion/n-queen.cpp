#include<iostream>
#include<bits/stdc++.h>
#define N 4
using namespace std;



void print2D(int board[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int board[][N], int row , int col)
{
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (i=row, j=col; j>=0 && i<4; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
}

// SC : O(N^2)

void Nqueen1(int board[N][N], int col )
{
    if(col==N)
    {
        cout<<"Arrangement : "<<endl;
        print2D(board);
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            Nqueen1(board,col+1);
            board[i][col]=0;
        }
    }
}



void print1D(int sel[])
{
    for(int i=0;i<N;i++)
        cout<<(i+1)<<","<<sel[i]+1<<endl;
    cout<<endl;
}

bool isValid(int sel[], int row,int col)
{
    //Column check
    for(int i=0;i<row;i++)
    {
        if(sel[i]==col)
            return false;
    }

    // Diagonal check
    for(int i=0;i<row;i++)
    {
        if(abs(row-i) == abs(col-sel[i]))
            return false;
    }
    return true;
}

// SC : O(N)

void Nqueen2(int sel[] , int index)
{
    if(index==N)
    {
        cout<<"Arrangement : "<<endl;
        print1D(sel);
        return;
    }

    for(int col=0;col<N;col++)
    {
        if(isValid(sel,index,col))
        {
            sel[index] =  col;
            Nqueen2(sel,index+1);
        }
    }
}

int main()
{
    int board[N][N];
    memset(board,0,sizeof(board));

    Nqueen1(board,0);

    int sel[N];
    memset(sel,0,sizeof(sel));
    Nqueen2(sel,0);

}