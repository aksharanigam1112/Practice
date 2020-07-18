#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxDiff(int arr[] , int i , int j , int k , int check)
{
    if(i>=j)
        return 0;
    
    if(check==k)
        return arr[j]-arr[i];
    
    return max(maxDiff(arr,i,j-1,k,check+1) , maxDiff(arr,i+1,j,k,check+1));
}

int main()
{
    int arr[] = {2,3,8,9,12,15,18,21,25,28,30,35};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int k=3;
    

    cout<<maxDiff(arr,0,size-1,k,1)<<endl;
}