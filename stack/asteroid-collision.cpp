// We are given an array asteroids of representing asteroids in a row.
// For each asteroid, the abs value represents its size, and the sign represents its direction 
// (+ve = right dir, -ve = left dir).Find out the state of the asteroids after all collisions. 
// If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
// NOTE : Two asteroids moving in the same direction will never meet & Each asteroid moves at the same speed.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void asteroidCollision(vector<int> arr) {
	int n = arr.size();

	if(n == 0 || n==1)
		return;

	stack<int> s;

	for(int i=0;i<n;i++) {
		// We have already resolved collisions 
		if(s.empty() || s.top() < 0)
			s.push(arr[i]);
		
		else {

			// Collision 
			if(arr[i] < 0) {

				while(!s.empty() && s.top() > 0 && abs(arr[i]) > s.top())
					s.pop();

				// After resolving collision, if stack empty or top < 0, then push 
				if(s.empty() || s.top() < 0 )
					s.push(arr[i]);

				// Both asteriods are of same size & move in opposite directions
				else if(!s.empty() && s.top() == abs(arr[i]))
					s.pop();
			}

			else
				s.push(arr[i]);
		}
	}

	vector<int>ans;

	while(!s.empty()) {
		ans.push_back(s.top());
		s.pop();		
	}

	reverse(ans.begin(), ans.end());
	for(int ele : ans)
		cout<<ele<<" ";

	cout<<endl;
}


int main() {
	// vector<int> arr = {1,-2,-2,-2};

	// vector<int> arr = {5,10,-5};

	vector<int> arr = {1,-1,-2,-2};

	// vector<int> arr = {8,-8};

	asteroidCollision(arr);
}
