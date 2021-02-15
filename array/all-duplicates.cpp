// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 
// some elements appear twice and others appear once.
// Find all the elements that appear twice in this array.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findAllDuplicates(vector<int>&arr, int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1]>0)
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        else
            cout<<abs(arr[i])<<" ";
    }
    cout<<endl;
}

void findAllMissing(vector<int>&arr, int n)
{
    for(int i=0;i<n;i++) 
    {
        while(arr[i] != i+1 && arr[i] != arr[arr[i]-1]) 
            swap(arr[i],arr[arr[i]-1]);
            
    }
        
    for(int i=0; i<n;i++) 
    {
        if(arr[i] != i+1) 
            cout<<i+1<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr = {4,3,2,7,8,2,3,1};
    int n = arr.size();
    
    cout<<"Duplicates are : ";
    findAllDuplicates(arr,n);
    cout<<"Missing are : ";
    findAllMissing(arr,n);
}