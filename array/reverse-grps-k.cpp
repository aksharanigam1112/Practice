// Given an array, reverse every sub-array formed by consecutive k elements
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void reverse(int arr[], int i, int j)
{
    while(i<j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void reverseK(int arr[], int beg, int end, int k)
{
    if(end-beg+1 < k)
        return ;
    
    for(int i=beg;i<end;i+=k)
    {
        if(i+k-1 < end)
            reverse(arr,i,i+k-1);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    reverseK(arr,0,size,3);
    print(arr,size);
}   