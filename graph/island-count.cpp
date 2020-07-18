#include<iostream>
#include<bits/stdc++.h>
#define r 5
#define c 5
using namespace std;

int isSafe(int arr[r][c], int row, int col, map<int,bool>&visited) 
{ 
    return ((row >= 0) && (row < r) && (col >= 0) && (col < c) 
        && arr[row][col] && visited.find(row*c+col)==visited.end()); 
} 

void dfs(int arr[r][c], int i, int j, map<int,bool>&visited)
{
    visited[i*c+j]=true;
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
  
    for(int k=0; k<8; k++)
    { 
        if (isSafe(arr,i+rowNbr[k], j+colNbr[k], visited)) 
            dfs(arr, i+rowNbr[k], j+colNbr[k], visited); 
    } 
}

int island(int arr[r][c])
{
    map<int,bool>visited;
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==1 && visited.find(i*c+j)==visited.end())
            {
                dfs(arr,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[r][c] = {{1,1,0,0,0}, 
                     {0,1,0,0,1}, 
                     {1,0,0,1,1}, 
                     {0,0,0,0,0}, 
                     {1,0,1,0,1}}; 
    
    cout<<"No. of islands are : "<<island(arr)<<endl;
}