#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int size)
{
    if(i>=size)
        return;
    if(2*i+1>=size)
        return;
    int max = 2*i+2 >=size ? 2*i+1 : (arr[2*i+1] > arr[2*i+2] ? 2*i+1 : 2*i+2);

    if(arr[max]>arr[i])
    {
        swap(arr[max],arr[i]);
        heapify(arr,max,size);
    }
}

void makeMaxHeap(int arr[] , int size)
{
    for(int i=size/2 ; i>=0 ; i--)
    {
        heapify(arr,i,size);
    }
}

void printHeapSort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void heapSort(int arr[],int size)
{
    while(size>0)
    {
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,0,size);
    }
}

int main()
{
    int arr[] = {10,2,3,41,5,6,15,8,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    makeMaxHeap(arr,size);
    heapSort(arr,size);
    printHeapSort(arr,size);
}