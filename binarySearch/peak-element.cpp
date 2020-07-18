// A peak element is an element that is greater than its neighbors.
#include<iostream>
using namespace std;

// Brute Force TC : O(N)

// Binary Search TC : O(LogN)
int findPeak(int arr[], int size)
{
    int low=0, high=size-1,mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        // cout<<low<<" "<<high<<" "<<mid<<endl;

        if((mid==0 || arr[mid]>arr[mid-1]) && (mid==size-1 || arr[mid]>arr[mid+1]))
            return arr[mid];

        if(mid!=0 && arr[mid]<arr[mid-1] )
            high = mid-1;
        else
            low = mid+1;
    }
    // return -1;
}

int main()
{
    int arr[] = {2,2,2,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Peak element is : "<<findPeak(arr,size)<<endl;
}