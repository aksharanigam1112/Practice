// Returns the Number of sub sequences (or subsets) which are divisible by k.
#include<iostream> 
#include <bits/stdc++.h> 
using namespace std; 

int sumSubSequence(int arr[], int size, int k) 
{ 
	int sum = accumulate(arr,arr+size,0); 
	
	int dp[size + 1][sum + 1];
    memset(dp,0,sizeof(dp)); 

	for (int i = 0; i <= size; i++) 
		dp[i][0] = 1; 

	for(int i=1; i<=size; i++) 
    { 
		dp[i][arr[i-1]]++; 
		for (int j=1; j<=sum; j++) 
        { 
			if (dp[i-1][j] > 0) 
            { 
				dp[i][j]++; 
				dp[i][j + arr[i-1]]++; 
			} 
		}
        // cout<<"For i "<<i<<" :-\t";
        // for(int k=0;k<=sum;k++)
        // {
        //     cout<<dp[i][k]<<" ";
        // } 
        // cout<<endl;
	} 

	int count = 0; 
	for (int j=1; j<=sum; j++) 
    {
		// if (dp[size][j] > 0) 
            if (j%k == 0) 
				count += dp[size][j]; 
    }
	return count; 
} 

int main() 
{ 
	int arr[] = { 1, 2, 3, 4 }; 
	int k = 2; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	cout<<"No. of subsets are :- "<<sumSubSequence(arr, size, k)<<endl; 
} 
