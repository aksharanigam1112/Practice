#include<iostream>
#define size 3
#define MAX 99999;
using namespace std;

// Brute Force TC : O(N^N)
int minCostBF(int arr[][size], int start, int end)
{
    if(start==end)
        return 0;
    
    int min_cost = MAX;
    for(int k=start;k<end;k++)
    {
        min_cost = min(min_cost, minCostBF(arr,start,k) + minCostBF(arr,k+1,end)
                        + arr[0][start]*arr[1][k]*arr[1][end]);
    }
    return min_cost;
}

// Optimized BU 1 TC : O(N^3)
int minCostBU1(int arr[][size])
{
    // int n =size+1;
    int dp[size][size];

	for(int i=0;i<size;i++)
		dp[i][i] = 0;

	for (int L=2; L<=size;L++)
    { 
        // cout<<"\n\nFor len : "<<L<<endl;
        for (int i=0; i<=size-L; i++)  
        { 
            int j = i+L-1; 
            // cout<<"For i : "<<i<<" j : "<<j<<endl;
            int min_cost = MAX;
             
            for (int k=i; k<j; k++) 
            { 
                min_cost = min(min_cost, dp[i][k]+dp[k+1][j]+arr[0][i]*arr[1][k]*arr[1][j]); 
                // cout<<"\tMin cost : "<<min_cost<<endl;
            } 
            dp[i][j] = min_cost;
        } 
    } 
    
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][size-1]; 
} 



int main()
{
    int arr[2][size] = {{3,4,2},{4,2,1}};
    
    cout<<"Min cost Matrix Multiplication BF : "<<minCostBF(arr,0,size-1)<<endl;
    cout<<"Min cost Matrix Multiplication BU1 : "<<minCostBU1(arr)<<endl;
}