#include<iostream>
#include<climits>
#include<vector>
#define col 4
using namespace std;

// Brute Force TC : O(2^N) & SC : O(N)
int knapsackBF(int arr[][col], int index, int capacity)
{
    if(index == 0)
        return capacity >= arr[0][0] ? arr[1][0] : 0;

    int include = arr[0][index] <= capacity ? arr[1][index] + knapsackBF(arr,index-1,capacity-arr[0][index]) : 0;
    
    int exclude = knapsackBF(arr,index-1,capacity);

    return max(include,exclude);
}

// Bottom Up TC : O(N*capacity) & SC : O(N*Capacity)
int knapsackBU(int arr[][col], int capacity)
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

// TC : O(N) & SC : O(Capacity)
int bottomUpOptimized(int arr[][col], int capacity) {
    
    vector<int> dp(capacity+1,0);

    for(int i=0;i<col;i++){

        for(int w=capacity;w>=0;w--){

            int include = arr[0][i] <= w ? arr[1][i] + dp[w-arr[0][i]] : 0;
            int exclude = dp[w];

            dp[w] = max(include, exclude);
        }
    }

    return dp[capacity];
}


int main()
{
    // 1st row has weights/space occupied
    // 2nd row has cost/values

    // int capacity = 50;
    // int arr[][3] = {
    //     { 10, 20, 30 },
    //     { 60, 100, 120 }
    // };

    int capacity = 5;
    int arr[][col] = {
        {1,2,4,5},
        {5,4,8,9}
    };

    cout<<"Max values BF : "<<knapsackBF(arr,col-1,capacity)<<endl;

    cout<<"Max values BU : "<<knapsackBU(arr,capacity)<<endl;

    cout<<"Max values BU optimized : "<<bottomUpOptimized(arr,capacity)<<endl;
}
