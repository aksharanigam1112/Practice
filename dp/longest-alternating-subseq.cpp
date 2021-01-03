// Given an array find the length of the longest alternating subsequence in the array 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force  TC : O(N*N) 
int alternateBF(int arr[], int start, int end, bool prevCheck)
{
    int res = 0;
    for(int i=start;i<end;i++)
    {
        // Include and check if the prev was smaller element
        if(prevCheck==true && arr[i-1]<arr[i])
            res = max(res,1+alternateBF(arr,i+1,end,!prevCheck));

        // Include and check if the prev was greater element
        else if(prevCheck==false && arr[i-1]>arr[i])
            res = max(res,1+alternateBF(arr,i+1,end,!prevCheck));

        // Exclude the current element
        else
            res = max(res,alternateBF(arr,i+1,end,prevCheck));
    }
    return res;
}

// Bottom UP TC : O(N^2)    SC : O(N)
int alternateBU(int arr[], int size)
{
    // Dp[i][0] : arr[i-1] < arr[i] 
    // Dp[i][1] : arr[i-1] > arr[i]  
    int dp[size][2];

    memset(dp,0,sizeof(dp));

    dp[0][0] = dp[0][1] = 1;
    int res = 0;

    for(int i=1;i<size;i++)
    {
        for(int j=0;j<i;j++)
        {
            // prev element is smaller than current element
            if(arr[i] > arr[j])
                dp[i][0] = max(dp[i][0],1+dp[j][1]);
            // prev element is larger than current element
            if(arr[i] < arr[j])
                dp[i][1] = max(dp[i][1],1+dp[j][0]);
        }
        res = max(res,max(dp[i][0],dp[i][1]));
    }
    return res;
}

int main()
{
    int arr[] = {8,9,6,4,5,7,3,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Longest alternating subsequence length BF : "<<max(alternateBF(arr,0,size,true),alternateBF(arr,0,size,false))<<endl; 
    cout<<"Longest alternating subsequence length BU : "<<alternateBU(arr,size)<<endl; 
}