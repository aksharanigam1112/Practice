// Given a binary matrix, find out the maximum size square sub-matrix with all 1s. 
#include<iostream>
#include<climits>
#define n 6
using namespace std;

// Optimized Brute Force TC : O(N^3)
void calSum(int arr[n][n],int dp[n][n])
{
    // Column-wise Add
    for(int i=0;i<n;i++)        // Col Change
    {
        for(int j=0;j<n;j++)    // Row change
        {
            if(i!=0)
                dp[j][i] = dp[j][i-1]+arr[j][i];
            else
                dp[j][i] = arr[j][i];
        }
    }

    //Row-wise Add
    for(int i=0;i<n;i++)        // Row Change
    {
        for(int j=0;j<n;j++)    // Column change
        {
            if(i!=0)
                dp[i][j] = dp[i-1][j]+arr[i][j];
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int maxSubmatrix(int arr[n][n])
{
    int dp[n][n]={0};
    calSum(arr,dp);

    int maxSize = INT_MIN;
    // int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int l=1;l<n;l++)
            {
                int Rs=i, Cs=j, Re=i+l-1, Ce=j+l-1,sum=0;
                // if(Rs>0 && Cs>0 && Re<n && Ce<n )
                // {
                    sum = dp[Re][Ce] - dp[Rs-1][Ce] - dp[Re][Cs-1] + dp[Rs-1][Cs-1];

                    if(sum==l*l)
                    {    
                        maxSize = max(maxSize,l);
                        cout<<"Matrix dim : "<<Rs<<" "<<Cs<<","<<Re<<" "<<Ce<<" Size : "<<l<<" Sum : "<<sum<<endl; 
                        // count++;
                    }
                // }
            }
        }
    }
    // cout<<"Total such sqaures : "<<count<<endl;
    return maxSize;
}

// Bottom Up TC : O(N^2)

int maxSubmatrix2(int arr[n][n])
{
    int dp[n][n]={0};

    for(int i=0;i<n;i++)
        dp[i][0] = arr[i][0];

    for(int i=0;i<n;i++)
        dp[0][i] = arr[0][i];

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[i][j]==0)
                dp[i][j]=0;
            else
                dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+1;
        }
    }

    int maxSize=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxSize = max(maxSize,dp[i][n-1]);
    }    
    return maxSize;
}


int main()
{
    int arr[n][n] = {{1,1,1,1,1,1},
                    {0,1,1,0,1,1},
                    {1,0,1,1,1,0},
                    {1,0,1,1,1,1},
                    {1,1,1,1,1,1},
                    {0,1,1,1,1,0}};
    // int dp[n][n]={0};
    cout<<"Max size square : "<<maxSubmatrix2(arr)<<endl;
}