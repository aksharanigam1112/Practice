//Given an array arr[], find the maximum j – i such that arr[j] > arr[i] ; j>i
#include<iostream>
using namespace std;


// TC : O(2^N)
int lenDiff(int arr[], int i, int j)
{
    if(i>j)
        return -1;

    if(arr[j]>arr[i])
        return j-i;
    
    return max(lenDiff(arr,i+1,j),lenDiff(arr,i,j-1));
    
}



int main()
{
    int arr[] =  {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max len diff : "<<lenDiff(arr,0,n-1)<<endl;
}