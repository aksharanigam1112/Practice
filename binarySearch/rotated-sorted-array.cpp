// A sorted array is rotated at some pivot point. 
// Find the min element and search a given number. 
#include<iostream>
using namespace std;

int findPivot(int arr[], int size)
{
    if(arr[0]<arr[size-1])
        return 0;
    
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid = (low+high)/2;

        if(mid==0 && arr[mid]>arr[mid+1])
            return mid+1;

        else if(mid==size-1 && arr[mid] > arr[mid-1])
            return mid;

        else if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
            return mid+1;

        else if(arr[mid] < arr[mid+1] && arr[mid] < arr[mid-1])
            return mid;
        

        if(arr[low]<=arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return mid;
}

int findMin(int arr[], int size)
{
    int pivot = findPivot(arr,size);
    return arr[pivot];
}

int search(int arr[], int size, int target)
{
    if(size==0)
        return -1;
    if(size==1)
        return arr[0]==target ? 0:-1;

    int pivot = findPivot(arr,size);
    if(target>=arr[pivot] && target<=arr[size-1])
    {
        int low = pivot, high=size-1,mid;
        while(low<=high)
        {
            mid = (low+high)/2;

            if(arr[mid]==target)
                return mid;
            if(arr[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
    } 
    else if(target>=arr[0] && target<=arr[pivot-1])
    {
        int low=0,high=pivot-1,mid;
        while(low<=high)
        {
            mid = (low+high)/2;

            if(arr[mid]==target)
                return mid;
            if(arr[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
    }
    else
        return -1;
}

int main()
{
    int arr[] = {2,2,2,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Pivot point of rotated sorted array : "<<findPivot(arr,size)<<endl;
    cout<<"Min Element : "<<findMin(arr,size)<<endl;
    cout<<"Position of search element : "<<search(arr,size,0)<<endl;
}