#include<iostream>
using namespace std;

// Brute Force O(n)

// Using Binary search as the array is sorted O(log n)
int magicIndex(int*arr,int n)
{
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(arr[mid]==mid)
            return mid;
        if(mid > arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

int main()
{
    int arr[] = {-1,0,1,2,4,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Magic Index : "<<magicIndex(arr,n)<<endl;
}