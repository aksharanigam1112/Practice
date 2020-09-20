// Given a circular array, find the max sum subarray.
#include<iostream>
#include<numeric>
using namespace std;

// Find the min sum seq and then remove it. Then we will be left with max sum circular seq
// we return max(max sum circular subarray , max sum non-circular subarray)

int kadanes(int arr[], int size)
{
    int maxsoFar = arr[0], maxEnding = arr[0];

    for(int i=1;i<size;i++)
    {
        maxEnding += arr[i];
        // If max sum is -ve, set it to 0
        maxEnding = max(maxEnding,0); 
        maxsoFar = max(maxsoFar,maxEnding);
    }
    return maxsoFar;
}

int kadaneCircular(int arr[], int size)
{
    int maxSum = kadanes(arr,size);

    // Invert the signs of all the elements
    for(int i=0;i<size;i++)
        arr[i] = -arr[i];
    
    int negMaxSum = kadanes(arr,size);
    
    // Restore the sign
    for(int i=0;i<size;i++)
        arr[i] = -arr[i];

    // max( max of non-circular subarray , max of circular subarray by removing min sum)
    return max(maxSum,negMaxSum + accumulate(arr,arr+size,0));
}

int main()
{
    int arr[] = {2,1,-5,4,-3,1,-3,4,-1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max circular subarray sum : "<<kadaneCircular(arr,size)<<endl;
}