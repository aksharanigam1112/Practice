// Level of water filled between the buildings
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Using array 	-	TC : O(N) & SC : O(N)
int trapRainwater1(vector<int> &arr) {
	int n = arr.size();
	vector<int> maxFromLeft(n);
	vector<int> maxFromRight(n);

	maxFromLeft[0] = arr[0];
	for(int i=1;i<n;i++){
		maxFromLeft[i] = max(maxFromLeft[i-1], arr[i]);
	}


	maxFromRight[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--) {
		maxFromRight[i] = max(maxFromRight[i+1], arr[i]);
	}

	int water = 0;
	for(int i=1;i<n-1;i++) {

		int minEle = min(maxFromLeft[i], maxFromRight[i]);
		water += minEle - arr[i];
	}
	return water;
}

// Using stack 	-	TC : O(N) & SC : O(N)
int trapRainwater2(vector<int> &arr) {
	// pair {element, position}
	stack<pair<int,int>> s;

	int water = 0;

	for(int i=0;i<arr.size();i++) {

		// Stack top height < current height => replace & calculate
		while ((!s.empty()) && (s.top().first < arr[i]) ){

			int height = s.top().first;
			s.pop();
			
			// stack is empty => no ele on the left boundry
			if(s.empty()) {
				break;
			}
	
			// distance between the left & the right of the popped ele 
			int dist = (i - s.top().second - 1);
			int level = min(s.top().first , arr[i]) - height;
			water += dist * level;
		}

		s.push({arr[i], i});
	}

	return water;
}

// Using 2 pointer 	-	TC : O(N) & SC : O(1)
int trapRainwater3(vector<int> arr) {
	int l = 0, r = arr.size()-1, left_max = 0, right_max = 0, water = 0;

	while(l<=r) {

		// For ele at index l
		// Since we have traversed all ele's to the left of l, left_max is known 
		// For the right max of l, We can say that the right max would always be >= current r_max here
		// So, min(left_max,right_max) would always equal to left_max in this case
		// Increment l.
		if(left_max <= right_max) {
			water += max(0, left_max - arr[l]); 
	        left_max = max(left_max, arr[l]); 
	        l++; 
		} 


		// Consider Element at index r
		// Since we have traversed all elements to the right of r, right_max is known
		// For the left max of l, We can say that the left max would always be >= current l_max here
		// So, min(left_max,right_max) would always equal to right_max in this case
		// Decrement r.
		else {
			water += max(0, right_max - arr[r]);
			right_max = max(right_max, arr[r]);
			r--;
		}
	}

	return water;
}

int main() {
	// vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
	// vector<int> heights = {5,10,8,6,12,9,4,5,6};
	vector<int> heights = {3, 0, 2, 0, 4};

	cout<<"Water level collected using arrays : "<<trapRainwater1(heights)<<endl;
	cout<<"Water level collected using stack : "<<trapRainwater2(heights)<<endl;
	cout<<"Water level collected using pointers : "<<trapRainwater3(heights)<<endl;
}
