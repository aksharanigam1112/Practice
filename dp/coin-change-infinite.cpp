#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(N^N) 	& 	SC : O(N) 
int recursion(vector<int>&arr, int target) {

	if(target == 0)
		return 0;

	if(target < 0)
		return INT_MAX;

	int min_cost = INT_MAX;

	for(int i=0;i<arr.size();i++) {
		
		int ans = recursion(arr, target-arr[i]);
		if(ans != INT_MAX)
			min_cost = min(min_cost, 1+ans);
	}

	return min_cost;
}

// TC : O(N^2) 	& 	SC : O(N)
int topDown(vector<int>&arr, vector<int>&dp, int target) {

	if(target == 0)
		return 0;

	if(target < 0)
		return INT_MAX;

	if(dp[target] != -1)
		return dp[target]; 

	int min_cost = INT_MAX;

	for(int i=0;i<arr.size();i++) {
		
		int ans = recursion(arr, target-arr[i]);
		if(ans != INT_MAX)
			min_cost = min(min_cost, 1+ans);
	}

	dp[target] = min_cost;
	return dp[target];
}

// TC : O(N^2) 	& 	SC : O(N) 
int bottomUp(vector<int>&arr, int target) {

	vector<int>dp(target+1, INT_MAX);
	dp[0] = 0;

	// Target
	for(int i=1;i<=target;i++) {

		// Coins
		for(int j=0;j<arr.size();j++) {

			if(i - arr[j] >= 0 && dp[i - arr[j]] != INT_MAX)
				dp[i] = min(dp[i], 1+dp[i - arr[j]]);
		}
	}

	return dp[target];
}


int main() {
	vector<int> arr = {1,2,5,7};
	int target = 11;

	int ans1 = recursion(arr, target);
	cout<<"Min coins required using recursion : "<<(ans1 == INT_MAX ? -1 : ans1)<<endl;

	vector<int> dp(target+1, -1);
	int ans2 = topDown(arr, dp, target);
	cout<<"Min coins required using Top Down : "<<(ans2 == INT_MAX ? -1 : ans2)<<endl;

	int ans3 = bottomUp(arr, target);
	cout<<"Min coins required using Bottom Up : "<<(ans3 == INT_MAX ? -1 : ans3)<<endl;
	
}
