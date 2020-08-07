// Find the term which is missing in the AP series
#include<iostream>
using namespace std;
// Brute Force TC : O(N)

// TC : O(LogN)
int missingAPterm(int arr[], int size)
{
    int diff = (arr[size-1] - arr[0])/size;
    int low = 0, high = size-1 , mid;

    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(mid+1<size && arr[mid+1]-arr[mid]!=diff)
            return arr[mid]+diff;
        if(mid-1>=0 && arr[mid]-arr[mid-1]!=diff)
            return arr[mid]-diff;
        
        if(arr[mid] == arr[0]+mid*diff)
            low = mid+1;
        else
            high = mid-1;
    }
}

int main()
{
    int arr[] = {10,15,25,30,35};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Missing term is : "<<missingAPterm(arr,size)<<endl;
}