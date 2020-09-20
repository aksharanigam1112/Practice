// Given an array, find the largest sum subarray 
#include<iostream>
using namespace std;

// Kadane's Algorithm
int kadane(int arr[], int size)
{
    int curr_sum=arr[0] , max_sum=arr[0];
    for(int i=1;i<size;i++)
    {
        curr_sum = max(arr[i] , curr_sum+arr[i]);
        max_sum = max(max_sum , curr_sum);
    }
    return max_sum;
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max sum subarray is : "<<kadane(arr,n)<<endl;
}