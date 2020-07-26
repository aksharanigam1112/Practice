// Given a sorted array A and a target value B, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
#include<iostream>
using namespace std;

int insertPos(int arr[], int size, int target)
{
    int low=0, high = size, mid;
    while(low<=high)
    {
        mid = ( high + low ) / 2;
        if( arr[mid]== target )
            break;
            
        else if( arr[mid] > target)
            high=mid-1;

        else 
            low= mid+1;
    }
    
    mid = ( high + low ) / 2;
    if (target<=arr[mid])
        return mid;
    else 
        return mid+1;
}

int main()
{
    int arr[] = {1,2,3,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 8;
    cout<<"Insert position : "<<insertPos(arr,size,target)<<endl;
}