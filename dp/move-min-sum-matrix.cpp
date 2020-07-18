#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define N 3
#define M 4
using namespace std;

// Brute Force TC : O(2^N)
int moveBF(int arr[M][N] , int i , int j )
{
    if(i>=M || j>=N  || (N==0 && M==0))
        return INT_MAX;
        
    if(i==M-1 && j==N-1)
        return arr[i][j];

    return arr[i][j] + min(moveBF(arr,i+1,j) , moveBF(arr,i,j+1)); 
}

// Bottom Up TC : O(N*M) SC : O(N*M)
int moveBU(int arr[M][N])
{
    int dp[M][N];
    memset(dp,0,sizeof(dp));
    
    // Fill 1st row
    for(int i=0;i<N;i++)
    {
        dp[0][i] = i>0 ? arr[0][i]+dp[0][i-1] : arr[0][i];  
    }

    // Fill 1st col
    for(int i=0;i<M;i++)
    {
        dp[i][0] = i>0 ? arr[i][0]+dp[i-1][0] : arr[i][0];
    }

    for(int i=1;i<M;i++)
    {
        for(int j=1;j<N;j++)
        {
            dp[i][j] = arr[i][j] + min(dp[i-1][j] , dp[i][j-1]);
        }
    }

    cout<<endl;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[M-1][N-1];
}


int main()
{
    int arr[M][N] = {{1,3,1}, {1,5,1}, {4,2,1}, {1,2,0}};
    
    cout<<"Min Sum BF :- "<<moveBF(arr,0,0)<<endl;
    cout<<"Min Sum BU :- "<<moveBU(arr)<<endl;
    
}