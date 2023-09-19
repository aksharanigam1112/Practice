// Given a fence with n posts and k colors, find out the no of ways of painting the fence 
// s.t at most 2 adjacent posts have the same color. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(2^N)	&	SC : O(N)
int recursion(int n, int k) {

	if(n==1)
		return k;

	if(n==2)
		return k*k;

	return recursion(n-2, k) * (k-1) + recursion(n-1, k) * (k-1);
}

// TC : O(N)	& 	SC : O(N)
int topDown(int n, int k, vector<int> &dp) {

	if(n==1)
		return k;

	if(n==2)
		return k*k;

	if(dp[n] != -1)
		return dp[n];

	dp[n] = topDown(n-2, k, dp) * (k-1) + topDown(n-1, k, dp) * (k-1);
	return dp[n];
}

// TC : O(N)	& 	SC : O(N)
int bottomUp(int n, int k) {

	if(n==1)
		return k;

	if(n==2)
		return k*k;

	vector<int> dp(n+1);
	dp[1] = k;
	dp[2] = k*k;
	

	for(int i=3;i<=n;i++){

		dp[i] = dp[i-2] * (k-1) + dp[i-1] * (k-1);	
	}

	
	return dp[n];
}

// TC : O(N)	& 	SC : O(1)
int bottomUp2(int n, int k) {

	if(n==1)
		return k;

	if(n==2)
		return k*k;

	int prev2 = k, prev1 = k*k;
	

	for(int i=3;i<=n;i++){

		int curr = prev2 * (k-1) + prev1 * (k-1);	

		prev2 = prev1;
		prev1 = curr;
	}

	
	return prev1;
}

int main() {
	int n=2, k=4;

	cout<<"Painting fence with k colours using recursion : "<<recursion(n,k)<<endl;

	vector<int> dp(n+1, -1);
	cout<<"Painting fence with k colours using top down : "<<topDown(n,k,dp)<<endl;	

	cout<<"Painting fence with k colours using bottom up : "<<bottomUp(n,k)<<endl;
	cout<<"Painting fence with k colours using optimized bottom up : "<<bottomUp2(n,k)<<endl;
}
