// Find the next smaller & greater to an element in an array 
// from both left & right sides, assuming the array in non-cyclic

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for(int ele : arr) {
		cout<<ele<<" ";
	}
	cout<<endl;
}

void nearestGreaterToTheRight(vector<int>& arr) {
	stack<int> s;
	vector<int> ans(arr.size(), -1);

	for(int i=arr.size()-1; i>=0; i--) {
		
		while(!s.empty() && s.top() < arr[i])
			s.pop();

		if (!s.empty() && s.top() > arr[i])
			ans[i] = s.top();

		s.push(arr[i]);	
	}

	print(ans);
}

void nearestSmallerToTheRight(vector<int>& arr) {
	stack<int> s;
	vector<int> ans(arr.size(), -1);
	
	for(int i=arr.size()-1; i>=0; i--) {
		
		while(!s.empty() && s.top() > arr[i])
			s.pop();

		if (!s.empty() && s.top() < arr[i])
			ans[i] = s.top();

		s.push(arr[i]);	
	}

	print(ans);
}


void nearestGreaterToTheLeft(vector<int>& arr) {
	stack<int> s;
	vector<int> ans(arr.size(), -1);

	for(int i=0; i<arr.size(); i++) {
		
		while(!s.empty() && s.top() < arr[i])
			s.pop();

		if (!s.empty() && s.top() > arr[i])
			ans[i] = s.top();

		s.push(arr[i]);	
	}

	print(ans);
}

void nearestSmallerToTheLeft(vector<int>& arr) {
	stack<int> s;
	vector<int> ans(arr.size(), -1);

	for(int i=0; i<arr.size(); i++) {
		
		while(!s.empty() && s.top() > arr[i])
			s.pop();

		if (!s.empty() && s.top() < arr[i])
			ans[i] = s.top();

		s.push(arr[i]);	
	}

	print(ans);
}

int main() {
	// vector<int> arr = {13,7,6,12};
	// vector<int> arr = {4,5,2,25};
	vector<int> arr = {1,6,4,10,2,5};

	cout<<"Original array : ";
	print(arr);

	cout<<"Nearest greater to the right : ";
	nearestGreaterToTheRight(arr);

	cout<<"Nearest smaller to the right : ";
	nearestSmallerToTheRight(arr);

	cout<<"Nearest greater to the left : ";
	nearestGreaterToTheLeft(arr);

	cout<<"Nearest smaller to the left : ";
	nearestSmallerToTheLeft(arr);
}
