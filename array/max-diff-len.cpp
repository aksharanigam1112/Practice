// Given an array arr[], find the maximum j – i such that arr[j] > arr[i] ; j>i
#include<iostream>
using namespace std;

// Brute Force  TC : O(N^2)

// TC : O(NLogN)
int maxDiffLen(int arr[], int size)
{
    int maxFromEnd[size];
    maxFromEnd[size-1] = arr[size-1];
    
    for(int i=size-2; i>=0; i--) 
        maxFromEnd[i] = max(maxFromEnd[i + 1], arr[i]);
 
    int result = 0;
 
    for(int i=0;i<size;i++)
    {
        int low = i+1, high=size-1, ans=i;
 
        while (low <= high) 
        {
            int mid = (low + high) / 2;
 
            if(arr[i]<=maxFromEnd[mid]) 
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
        result = max(result, ans - i);
    }
    return result;
}

// TC : O(N) & SC : O(N)
int maxIndexDiff(int arr[], int n)
{
    int maxDiff = -1;
    int LMin[n] , RMax[n] ;
 
    LMin[0] = arr[0];
    for(int i=1; i<n; i++)
        LMin[i] = min(arr[i], LMin[i-1]);
 
    RMax[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        RMax[i] = max(arr[i], RMax[i+1]);
    
    int i=0, j=0;
    while (j<n && i<n) 
    {
        if (LMin[i] < RMax[j]) 
        {
            maxDiff = max(maxDiff, j-i);
            j++;
        }
        else
            i++;
    }
    return maxDiff;
}
 
int main()
{
    int arr[] =  {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
   
    cout<<"Max len diff optimized BF : "<<maxDiffLen(arr,n)<<endl;
    cout<<"Max len diff : "<<maxIndexDiff(arr,n)<<endl;
}