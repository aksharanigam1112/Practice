//For given types of coins, exchange the sum, with the given coins
// with repetition allowed
#include<iostream>
#define MAX 99999
using namespace std;

//Brute Force TC : O(2^N)
int coinsBF(int arr[], int index, int n)
{
    if(index<0 || n<0)
        return MAX;
    if(n==0)
        return 0;
    return min(1+coinsBF(arr,index,n-arr[index]) , coinsBF(arr,index-1,n));
}

//Bottom Up TC : O(N^2) SC : O(N^2)
int coinsBU(int arr[], int size, int n)
{
    int dp[size+1][n+1];

    for(int i=0;i<=n;i++)
        dp[0][i] = MAX;
    for(int i=0;i<=size;i++)
        dp[i][0] = 0;
    
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j-arr[i-1]<0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(1+dp[i][j-arr[i-1]] , dp[i-1][j]);
        }
    }
    cout<<endl;
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    return dp[size][n];
}


int main()
{
    int arr[] = {1,2,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 11;
    cout<<"Min coins required BF: "<<coinsBF(arr,size-1,n)<<endl;
    cout<<"Min coins required BU: "<<coinsBU(arr,size,n)<<endl;
}
