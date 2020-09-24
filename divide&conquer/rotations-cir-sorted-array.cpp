// Given a circularly sorted array of integers, find the no. of times the array is rotated. 
// Assume there are no duplicates and rotation is in anti-clockwise direction
#include<iostream>
using namespace std;

// No. of rotations = No. of elements before the min element in the array

// Linear Search of Min element TC : O(N)
// Binary Search of Min element TC : O(LogN)

int rotation(int arr[], int size)
{
    int start = 0, end = size , mid;

    while(start<=end)
    {
        mid = (start+end)/2;

        int next = (mid+1)%size , prev = (mid-1+size)%size;

        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;
            
        if(arr[mid] >= arr[end])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {8,9,10,2,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"No. of rotations : "<<rotation(arr,size)<<endl;
}