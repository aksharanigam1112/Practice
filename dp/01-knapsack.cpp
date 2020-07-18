#include<iostream>
#include<climits>
#define col 8
using namespace std;

//Brute Force TC : O(2^N)

int knapsackBF(int arr[][col], int index, int capacity)
{
    if(capacity<0 || index<0)
        return INT_MIN;
    if(capacity==0)
        return 0;
    return max(arr[1][index]+knapsackBF(arr,index-1,capacity-arr[0][index]) , knapsackBF(arr,index-1,capacity));
}

// Bottom Up TC : O(N*capacity)

int knapsackBU(int arr[][col],int capacity)
{
    int dp[col+1][capacity+1];

    for(int i=0;i<=col;i++)
        dp[i][0] = 0;
    
    for(int i=0;i<=capacity;i++)
        dp[0][i] = 0;
    
    for(int i=1;i<=col;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if (arr[0][i-1] <= j) 
                dp[i][j] = max( arr[1][i-1]+dp[i-1][j - arr[0][i-1]], dp[i-1][j]); 
            else
                dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[col][capacity];
}


int main()
{
    // 1st row has weights/space occupied
    // 2nd row has cost/values
    int arr[][col] = {{4,3,6,8,5,10,5,1},
                    {1,2,4,2,5,6,12,3}};

    cout<<"Max values BF : "<<knapsackBF(arr,col-1,10)<<endl;
    cout<<"Max values BU : "<<knapsackBU(arr,10)<<endl;
}