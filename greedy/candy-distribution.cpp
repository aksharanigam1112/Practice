// There are N children standing in a line. Each child is assigned a rating value.
// You are giving candies to these children subjected to the following requirements:
// 1) Each child must have at least one candy.
// 2) Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int candy(int ratings[], int n)
{
        
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=1;
        
    int total=0;
        
       
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1] && arr[i]<=arr[i-1])
            arr[i] = arr[i-1]+1;
        // cout<<"i : "<<i<<" Arr[i] : "<<arr[i]<<endl;
    }

    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1] && arr[i]<=arr[i-1]) 
            arr[i] = arr[i+1]+1;
        // cout<<"Arr[i] : "<<arr[i]<<endl;
    }
    
    for(int i=0;i<n;i++) 
        total+=arr[i];
        
    return total;                
}

int main()
{
    int arr[] ={1,0,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Minimum Candies required : "<<candy(arr,size)<<endl;
}