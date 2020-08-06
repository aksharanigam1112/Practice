//finding kth smallest using quick sort technique
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// can also use min heap TC : O(K logN)
// make k-sized heap TC : O(N logK)
// Prefer Randomized Quick Sort for large arrays to partiton

int partition(int arr[], int start, int end) 
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

int kthSmallest(int arr[],int start, int end, int k)
{
    if(start>end)
        return -1;

    int index = partition(arr,start,end);
    
    if(index+1==k)
        return arr[index];
    else
    {
        if(index<k)
            return kthSmallest(arr,index+1,end,k);
        else
            return kthSmallest(arr,start,index-1,k);
    }
}

int kthLargest(int arr[],int start, int end, int k)
{
    if(start>end)
        return -1;
    
    srand(time(NULL)); 
    if(end-start>0)
    {
        int random = start + rand() % (end - start); 
        swap(arr[random], arr[end]); 
    }
    int index = partition(arr,start,end);
    
    if(index+1==k)
        return arr[index];
    else
    {
        if(index<k)
            return kthLargest(arr,index+1,end,k);
        else
            return kthLargest(arr,start,index-1,k);
    }
}


int main()
{
    int arr[] = {8,10,1,2,15,18,3,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<"Kth Smallest :"<<kthSmallest(arr,0,size-1,k)<<endl;
    cout<<"Kth Largest :"<<kthLargest(arr,0,size-1,size-k+1)<<endl;
}