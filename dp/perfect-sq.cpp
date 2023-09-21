// Given a number N. Find the minimum number of squares of any number that sums to N
// For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) 
// but the output will be 1 as minimum number of square is 1 , i.e (10*10).

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Vector vector<int> 

int recursion(int target) {
	if(target == 0)
		return 0;

	int ans = INT_MAX;
	for(int i=1;i<=sqrt(target);i++){

		if(target >= pow(i,2))
			ans = 1 + min(ans, recursion(target-pow(i,2)));
	}

	return ans;
}

int topDown(int target, vector<Vector>&dp) {
	if(target == 0)
		return 0;

	// Perfect sq of any no with 1 = the no. itself 
	for(int i=1; i<=target; i++)
		dp[1][i] = i;


	int ans = INT_MAX;
	for(int i=2;i<=sqrt(target);i++){

		if(target >= pow(i,2)) {
			int ele = dp[i][target - pow(i,2)] != -1 ? dp[i][target - pow(i,2)] : 
														recursion(target-pow(i,2));
			ans = 1 + min(ans, ele);
		}

		else
			ans = dp[i-1][target];

		dp[i][target] = ans;
	}

	return dp[sqrt(target)][target];
}

int bottomUp(int target) {
	if(target == 0)
		return 0;

	int n = sqrt(target);
	vector<Vector> dp(n+1, Vector(target+1, 0)); 
	
	// Perfect sq of any no with 1 = the no. itself 
	for(int j=1; j<=target; j++)
		dp[1][j] = j;

	for(int i=2; i<=n; i++) {

		for(int j=1; j<=target; j++) {

			if(j >= pow(i,2))
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j - pow(i,2)]);
			
			else
				dp[i][j] = dp[i-1][j];	
		}
	}

	return dp[n][target];
}

int main() {
	// 15 = (3*3) + (2*2) + (1*1) + (1*1) => 4 
	int target = 15;
	int n = sqrt(target);

	cout<<"Min no. of ways to make the target using perfect sq using recursion : "<<recursion(target)<<endl;

	vector<Vector> dp(n+1, Vector(target+1, -1)); 
	cout<<"Min no. of ways to make the target using perfect sq using top down : "<<topDown(target, dp)<<endl;

	cout<<"Min no. of ways to make the target using perfect sq using bottom up : "<<bottomUp(target)<<endl;
}
