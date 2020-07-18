// Given a positive integer n, 
// find the least number of perfect square numbers (1, 4, 9, 16, ...) which sum to n.
#include<iostream>
#include<math.h>
#include<climits>
#include<vector>
using namespace std;

int change(vector<int>arr, int n)
{
    int dp[arr.size()][n+1];

    for(int i=0;i<=n;i++)
        dp[0][i]=i;

    for(int i=0;i<arr.size();i++)
        dp[i][0] = 0;

    for(int i=1;i<arr.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j< arr[i])
                dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = min(dp[i-1][j], 1+ dp[i][j-arr[i]]);
            }
        }
    }

    // for(int i=0;i<arr.size();i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[arr.size()-1][n];
}

int minSqSum(int n)
{
    vector<int>arr;
    int k = floor(sqrt(n));
    for(int i=1;i<=k;i++)
    {
        arr.push_back(i*i);
    }
    return change(arr,n);
}

int main()
{
    int n=13;
    cout<<"Least no. of perfect sq req : "<<minSqSum(n)<<endl;
}