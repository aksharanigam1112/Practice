//finding kth smallest using quick sort technique
//can also use min heap TC : O(K logN)
//make k-sized heap TC : O(N logK)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end) 
{ 
    int pivot = arr[end], i = start; 
    for (int j = start; j <end; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[end]); 
    return i; 
} 

void kthSmallest(int *arr,int start, int end, int k)
{
    if(start>end)
        return;

    int index = partition(arr,start,end);
    cout<<"Partition index : "<<index<<endl;
    if(index+1==k)
        cout<<arr[index]<<endl;
    else
    {
        if(index<k)
            kthSmallest(arr,index+1,end,k);
        else
            kthSmallest(arr,start,index-1,k);
    }
}

int main()
{
    int arr[] = {8,10,1,2,15,18,3,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
    cout<<"Kth Smallest :";
    kthSmallest((int*)arr,0,size-1,k);
}