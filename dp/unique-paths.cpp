#include<iostream>
using namespace std;

// Brute Force TC : O(2^N)
int uniqueBF(int i , int j, int m,int n)
{
    if(m==0 || n==0 || i>m || j>n)
        return 0;
    if(i==m && j==n)
        return 1;
    
    return uniqueBF(i+1,j,m,n) + uniqueBF(i,j+1,m,n);
}

// Bottom Up TC : O(N^2)
int uniqueBU(int m , int n)
{
    int dp[m][n];

    //Fill 1st row
    for(int i=0;i<n;i++)
        dp[0][i] = 1;
    
    //Fill 1st col
    for(int i=0;i<m;i++)
        dp[i][0] = 1;

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int n=2,m=3;
    cout<<"Total Unique paths BF:- "<<uniqueBF(1,1,m,n)<<endl;
    cout<<"Total Unique paths BU:- "<<uniqueBU(m,n)<<endl;
    
}