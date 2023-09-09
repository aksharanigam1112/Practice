// There are N houses built in a circular, each of which contains some value in it. 
// A thief is going to steal the maximum value of these houses, but he can’t steal in two adjacent houses

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(2^N) 	& 	SC : O(N) 
int recursion(vector<int>&arr, int index) {

	if(index >= arr.size())
		return 0;

	return max(
				arr[index] + recursion(arr, index+2), // include
				recursion(arr, index+1) // exclude
			);
}

// TC : O(N) 	& 	SC : O(N+N) 
int topDown(vector<int>&arr, vector<int>&dp, int index) {

	if(index >= arr.size())
		return 0;

	if(dp[index] != -1)
		return dp[index];

	dp[index] = max(arr[index] + topDown(arr, dp, index+2), topDown(arr, dp, index+1));
	return dp[index];
}


// TC : O(N) 	& 	SC : O(N) 
int bottomUp(vector<int>&arr) {
	int n = arr.size();
	if(n==0)
		return 0;
	
	if(n==1)
		return arr[0];

	vector<int> dp(n, 0);

	dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for(int i=2;i<n;i++) {

        dp[i] = max(
        	arr[i] + dp[i-2], // include
        	dp[i-1] //exclude
    	);
    }

    return dp[n-1];
}

// TC : O(N) 	& 	SC : O(1) 
int bottomUpOptimized(vector<int>&arr) {
	int n = arr.size();
	if (n == 0)
        return 0;
 
    int value1 = arr[0];
    if (n == 1)
        return value1;
 
    int value2 = max(arr[0], arr[1]);
    if (n == 2)
        return value2;

    int max_val;
    
    for (int i = 2; i < n; i++) {
        max_val = max(arr[i] + value1, value2);
        value1 = value2;
        value2 = max_val;
    }
 
    return max_val;
}

int houseRobbery(vector<int>&arr) {
	vector<int> temp1, temp2;

	temp1.assign(arr.begin(), arr.end()-1);
	temp2.assign(arr.begin()+1, arr.end());

	return max(bottomUpOptimized(temp1), bottomUpOptimized(temp2));
}

int main() {
	vector<int> arr = {2,1,3,7};

	cout<<"Maximum possible stolen value when linear using recursion : "<<recursion(arr, 0)<<endl;

	vector<int>dp(arr.size()+1, -1);
	cout<<"Maximum possible stolen value when linear using Top Down : "<<topDown(arr, dp, 0)<<endl;

	cout<<"Maximum possible stolen value when linear using Bottom Up : "<<bottomUp(arr)<<endl;

	cout<<"Maximum possible stolen value when linear using Bottom Up optimized : "<<bottomUpOptimized(arr)<<endl;

	cout<<"Maximum possible stolen value when circular :  "<<houseRobbery(arr)<<endl;
}
