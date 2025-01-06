// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(NlogN) & SC : O(1)
int minPlatformsNeeded1(vector<int> &arrival, vector<int> &dept) {

	sort(arrival.begin(), arrival.end());
	sort(dept.begin(), dept.end());


	int maxPlatforms = 0, i=0, j=0, curr = 0;

	while(i<arrival.size() && j<dept.size()) {
		if(arrival[i] <= dept[j]) {
			curr++;
			i++;
		} else {
			curr--;
			j++;
		}

		maxPlatforms = max(maxPlatforms, curr);
	}
	return maxPlatforms;
}


// --------------------------------------------------------------------------------

// Sweep Line Algorithm : 
// The idea is to convert the arrival time and departure time of each train 
// in the form of (x, y) coordinate, and then apply the algorithm 
// to find the maximum number of overlap at any time.

// TC : O(N + maxTime) & SC : O(maxTime)
int minPlatformsNeeded2(vector<int> &arrival, vector<int> &dept) {

	int maxDeptTime = 0;
	for(int ele : dept) {
		maxDeptTime = max(maxDeptTime, ele);
	}

	// To store the count of trains at each time
	vector<int> arr(maxDeptTime+2, 0);

	for(int i=0; i<arrival.size(); i++){
		arr[arrival[i]]++;
		arr[dept[i] + 1]--;
	}

	int maxPlatforms = 0, count = 0;
	for(int i=0; i<=maxDeptTime + 1; i++) {
		count += arr[i];
		maxPlatforms = max(maxPlatforms, count);
	}

	return maxPlatforms;
}

int main() {
	vector<int> arrival = {900, 950, 1100, 1500, 1800, 940};
	vector<int> dept = {910, 1200, 1120, 1130, 1900, 2000};

	cout<<"Min platforms needed using sort : "<<minPlatformsNeeded1(arrival, dept)<<endl;

	cout<<"Min platforms needed using sweap line : "<<minPlatformsNeeded2(arrival, dept)<<endl;
}
