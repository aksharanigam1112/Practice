// Given an array of n positive integers. 
// The task is to count the number of Arithmetic Progression subsequence in the array.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int APseq(int arr[], int size)
{
    int minarr = INT_MAX, maxarr = INT_MIN; 
  
    for(int i=0; i<size;i++) 
    { 
        minarr = min(minarr, arr[i]); 
        maxarr = max(maxarr, arr[i]); 
    } 
  
    // dp[i] is going to store count of APs ending with arr[i]. 
    // sum[j] is going to store sun of all dp[]'s with j as an AP element. 
    int dp[size], sum[1000001],ans = size+1; 
  
    for(int diff =(minarr-maxarr); diff<=(maxarr-minarr); diff++) 
    { 
        memset(sum, 0, sizeof(sum)); 
  
        for (int i=0; i<size; i++) 
        { 
            dp[i] = 1; 
  
            if(arr[i]-diff >= 1 && arr[i]-diff<=1000000) 
                dp[i] += sum[arr[i]-diff]; 
  
            ans += dp[i]-1; 
            sum[arr[i]] += dp[i]; 
        } 
    } 
    return ans; 
}


int main()
{
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"No. of subsequences are : "<<APseq(arr,size)<<endl;
}