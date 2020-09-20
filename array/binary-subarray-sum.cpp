// In an array of 0s and 1s, how many non-empty subarrays have sum S 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySum(int arr[], int size, int S)
{
    int ans=0, sum=0;
    map<int,int>hash;
        
        
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
            
        if(sum==S)
            ans++;
        if(hash.find(sum-S)!=hash.end())
            ans+= hash[sum-S];
        hash[sum]++;
    }
    return ans;
}

int main()
{
    int arr[] = {1,0,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"No. of subarrays with sum : "<<binarySum(arr,size,2)<<endl;
}