#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Bottom Up TC : O(N^2) SC : O(N)

int lisSum(int arr[], int size)
{
    int dp[size];
    for (int i=0; i<size; i++ )  
        dp[i] = arr[i];  
  

    for(int i=1;i<size;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<=arr[i])
                dp[i] = max(dp[i], dp[j]+arr[i]);
        }
    }
    
    int maxSum=0;
    for(int i=0;i<size;i++)
    {
        maxSum = max(maxSum,dp[i]);
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    return maxSum;
}

int main()
{
    int arr[] = {10,1,3,4,15,6,8,20,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max sum possible : "<<lisSum(arr,size)<<endl;
}