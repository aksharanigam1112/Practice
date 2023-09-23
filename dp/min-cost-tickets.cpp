// https://leetcode.com/problems/minimum-cost-for-tickets/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(3^N) & SC : O(N)
int recursion(vector<int> &days, vector<int> &costs, int i, int size) {

	if(i >= size)
		return 0;

	int passFor1 = costs[0] + recursion(days, costs, i+1, size);

	// The day you are standing (i.e day[i]) if you buy a 7-day pass, you can travel from today + 7 days 
	// i.e Day 1 to Day 7 can be travelled, so i (poinitng to the day we buy a ticket) has to be 
	// update till we reach Day 7, after which we have to buy another ticket.
	// Similarly for 30 days ......

	int index;
	// 7 day pass
	for(index = i; index<size && days[index] < days[i] + 7; index++);
	int passFor7 = costs[1] + recursion(days, costs, index, size);

	// 30 day pass
	for(index = i; index<size && days[index] < days[i] + 30; index++);
	int passFor30 = costs[2] + recursion(days, costs, index, size);

	return min(passFor1, min(passFor7, passFor30));
}

// TC : O(1) & SC : O(N)
int topDown(vector<int> &days, vector<int> &costs, int i, int size, vector<int>&dp){
	if(i >= size)
		return 0;

	if(dp[i] != -1)
		return dp[i];

	int passFor1 = costs[0] + topDown(days, costs, i+1, size, dp);

	int index;
	
	// 7 day pass
	for(index = i; index<size && days[index] < days[i] + 7; index++);
	int passFor7 = costs[1] + topDown(days, costs, index, size, dp);

	// 30 day pass
	for(index = i; index<size && days[index] < days[i] + 30; index++);
	int passFor30 = costs[2] + topDown(days, costs, index, size, dp);

	dp[i] = min(passFor1, min(passFor7, passFor30));
	return dp[i];
}

// TC : O(N) & SC : O(N)
int bottomUp(vector<int> &days, vector<int> &costs, int size) {

	vector<int> dp(size+1, 0);
	dp[size] = 0;

	for(int i=size-1;i>=0;i--){

		int passFor1 = costs[0] + dp[i+1];

		int index;
		
		// 7 day pass
		for(index = i; index<size && days[index] < days[i] + 7; index++);
		int passFor7 = costs[1] + dp[index];

		// 30 day pass
		for(index = i; index<size && days[index] < days[i] + 30; index++);
		int passFor30 = costs[2] + dp[index];

		dp[i] = min(passFor1, min(passFor7, passFor30));
	}

	return dp[0];
}

// Since we know that the size of monthly queue <= 30
// Similarly we know the cost of weekly queue <= 7
// Hence the space is contant => O(1)

// TC : O(N) & SC : O(1)
int bottomUpOptimized(vector<int> &days, vector<int> &costs) {

	// pair = {current day, cost till that day}
	queue<pair<int,int>> monthly;
	queue<pair<int,int>> weekly;
	
	int ans = 0;
	for(int d : days){

		// Step 1: Update the queue for expired days & remove them from Sliding window
		while(!weekly.empty() && weekly.front().first + 7 <= d)
			weekly.pop();

		while(!monthly.empty() && monthly.front().first + 30 <= d)
			monthly.pop();

		// Step 2 : Add cost for current day in the resp queues
		weekly.push({d, ans + costs[1]});
		monthly.push({d, ans + costs[2]});

		// Step 3 update ans
		ans = min(ans + costs[0], min(weekly.front().second, monthly.front().second));
	}

	return ans;
}

int main() {
	vector<int> days = {1, 4, 6, 7, 8, 20};

	// Pass for 1 day = Cost[0]
	// Pass for 7 days = Cost[1]
	// Pass for 30 days = Cost[2]
	vector<int> costs = {2, 7, 15};  

	cout<<"Min cost to travel using recursion : "<<recursion(days, costs, 0, days.size())<<endl;

	vector<int> dp(days.size()+1, -1);
	cout<<"Min cost to travel using top down : "<<topDown(days, costs, 0, days.size(), dp)<<endl;

	cout<<"Min cost to travel using bottom up : "<<bottomUp(days, costs, days.size())<<endl;

	cout<<"Min cost to travel using bottom up optimized : "<<bottomUpOptimized(days, costs)<<endl;
}
