// Given an array of integers and a target, find the number of ways we can reach the target 
// using the elements of the array indefinitely

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(N^Target) & SC : O(N)
int recursion(vector<int>&arr, int target) {
	if(target < 0)
		return 0;

	if(target == 0)
		return 1;

	int ans = 0;
	for(int i=0;i<arr.size();i++){
		ans += recursion(arr, target-arr[i]);
	}

	return ans;
}

// TC : O(Target) 
int topDown(vector<int>&arr, int target, vector<int>&dp) {
	if(target < 0)
		return 0;

	if(target == 0)
		return 1;

	if(dp[target] != -1)
		return dp[target];

	int ans = 0;
	for(int i=0;i<arr.size();i++){
		ans += topDown(arr, target-arr[i], dp);
	}

	dp[target] = ans;
	return dp[target];
}


// TC : O(N * Target) 
int bottomUp(vector<int>&arr, int target) {
	if(target < 0)
		return 0;

	if(target == 0)
		return 1;

	vector<int>dp(target+1, 0);
	dp[0] = 1;

	for(int i=1;i<=target;i++) {
		
		for(int j=0;j<arr.size();j++){

			if(i >= arr[j])
				dp[i] += dp[ i - arr[j] ];
		}
	}

	return dp[target];
}

int main() {
	vector<int> arr = {1,2,5};
	int target = 5;

	cout<<"Total no. of ways to make the target using recursion : "<<recursion(arr, target)<<endl;

	vector<int> dp(target+1, -1);
	cout<<"Total no. of ways to make the target using top down : "<<topDown(arr, target, dp)<<endl;

	cout<<"Total no. of ways to make the target using bottom up : "<<bottomUp(arr, target)<<endl;
}
