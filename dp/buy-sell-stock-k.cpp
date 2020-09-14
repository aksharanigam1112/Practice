// Max the dp if you can buy and sell the stock atmost K times
#include<iostream>
#include<climits>
using namespace std;

int maxProfit(int price[], int n, int k) 
{ 
	int dp[k + 1][n + 1]; 

	for (int i = 0; i <= k; i++) 
		dp[i][0] = 0; 

	for (int j = 0; j <= n; j++) 
		dp[0][j] = 0; 

	for (int i = 1; i <= k; i++) 
    { 
		int prevDiff = INT_MIN; 
		for (int j = 1; j < n; j++) 
        { 
			prevDiff = max(prevDiff, dp[i-1][j-1]-price[j-1]); 
			dp[i][j] = max(dp[i][j-1], price[j] + prevDiff); 
		} 
	} 
	return dp[k][n - 1]; 
} 

int main() 
{ 
	int k = 3; 
	int price[] = { 12, 14, 17, 10, 14, 13, 12, 15 }; 
	int n = sizeof(price) / sizeof(price[0]); 
	cout<<"Maximum dp is: "<<maxProfit(price, n, k); 
	return 0; 
} 
