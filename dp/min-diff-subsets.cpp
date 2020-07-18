#include<iostream>
#include<math.h>
#define MAX 1000000
using namespace std;

// Brute Force TC : O(2^N)
int minDiffBF(int arr[] , int s1 , int s2 , int index,int size)
{
    if(index>=size)
        return abs(s1-s2);
    
    int min_diff = abs(s1 - s2);
    int diff = min( minDiffBF(arr,s1-arr[index],s2+arr[index],index+1,size) , 
                     minDiffBF(arr,s1 ,s2 , index+1,size) );

    return min(min_diff , diff);
}

int TotalSum(int arr[] , int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    return sum;
}

// Bottom Up TC : O(N^2)
int minDiffBU(int arr[] , int size , int total)
{
    bool dp[size+1][total+1]; 
  
    // Fill 1st col 
    for (int i = 0; i <=size; i++) 
        dp[i][0] = true; 
    
    // Fill 1st row
    for (int i = 1; i <=total; i++) 
        dp[0][i] = false; 
  
    for (int i=1; i<=size; i++) 
    { 
        for (int j=1; j<=total; j++) 
        { 
            dp[i][j] = dp[i-1][j]; 
  
            if (arr[i-1] <= j) 
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]]; 
        } 
    } 
   
    int diff = MAX; 
      
    for (int j=total/2; j>=0; j--) 
    { 
        if (dp[size][j] == true) 
        { 
            diff = total-2*j; 
            break; 
        } 
    } 
    
    // cout<<endl;
    // for(int i=0;i<=size;i++)
    // {
    //     for(int j=0;j<=total;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return diff;
}

int main()
{
    int arr[] = {4,2,6,2,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int total = TotalSum(arr,size);
    cout<<"Min difference is BF :- "<<minDiffBF(arr,total,0,0,size)<<endl;
    cout<<"Min difference is BU :- "<<minDiffBU(arr,size,total)<<endl;
}