// Stealing from the houses to maximize the profit
#include<iostream>
using namespace std;
//Bottom Up TC : O(N) SC : O(N)

// Steaing from cosecutive houses not allowed 
int profit1(int arr[],int size)
{
    int dp[size];
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);

    for(int i=2;i<size;i++)
    {
        dp[i] = max(dp[i-1],arr[i]+dp[i-2]);
    }
    return dp[size-1];
}

// Steaing from not more than 2 cosecutive houses allowed 
int profit2(int arr[],int size)
{
    int dp[size];
    dp[0] = arr[0];
    dp[1] = max(dp[0],arr[1]+dp[0]);
    dp[2] = arr[2]+max(dp[0],dp[1]);

    for(int i=3;i<size;i++)
    {
        dp[i] = max(dp[i-1],
            max(arr[i]+dp[i-2], arr[i]+arr[i-1]+dp[i-3]));
    }
    return dp[size-1];
}



int main()
{
    int arr[] = {20,15,2,3,40};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Profit from no consc house : "<<profit1(arr,size)<<endl;
    cout<<"Profit from not more than 2 consc houses : "<<profit2(arr,size)<<endl;
}
