// Given an array of non -ve nos, representing the maximum jump one can take.
// Find the min no. of steps to reach the destination (last index position).
#include<iostream>
#include<climits>
using namespace std;
#define INF 9999999

// Brute Force TC :O(N^N)
int jumpsNeededBF(int arr[], int size, int index)
{
    if(index==size-1)
        return 0;

    int res = INF;
    for(int i=1;i<=arr[index];i++)
    {
        res = min(res,1+jumpsNeededBF(arr,size,index+i));
    } 
    return res;
}

// Bottom UP TC : O(N^2)    SC : O(N)
int jumpsNeededBU(int arr[], int size)
{
    if(arr[0]==0)
        return INF;
    int dp[size];

    for(int i=1;i<size;i++)
        dp[i] =  INF;
    
    dp[0] = 0;

    for(int i=0;i<size;i++)
    {
        for(int j=1;i+j<size && j<=min(size-1,arr[i]);j++)
        {
            dp[i+j] = dp[i+j]!=INF ? min(dp[i+j],dp[i]+1) : dp[i]+1;

        }
    }
    return dp[size-1];
}

int main()
{
    int arr[] = {4,2,0,3,2,0,1,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Min jumps to reach dest BF : "<<jumpsNeededBF(arr,size,0)<<endl;
    cout<<"Min jumps to reach dest BU : "<<jumpsNeededBU(arr,size)<<endl;
}