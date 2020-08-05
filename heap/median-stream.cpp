// Given a stream of nos. find the median of them.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Left side ==> MAX HEAP
// Right side ==> MIN HEAP

void printMedians(int arr[], int n) 
{ 
	// max heap  
	priority_queue<double>left_max; 

	// min heap  
	priority_queue<double,vector<double>,greater<double>>right_min; 

	double med = arr[0]; 
	left_max.push(arr[0]); 

	cout<<med<<endl; 

	for (int i=1; i < n; i++) 
	{ 
		double x = arr[i]; 

		// case1(left side heap has more elements) 
		if (left_max.size() > right_min.size()) 
		{ 
			if (x < med) 
			{ 
				right_min.push(left_max.top()); 
				left_max.pop(); 
				left_max.push(x); 
			} 
			else
				right_min.push(x); 

			med = (left_max.top() + right_min.top())/2.0; 
		} 

		// case2(both heaps are balanced) 
		else if (left_max.size()==right_min.size()) 
		{ 
			if (x < med) 
			{ 
				left_max.push(x); 
				med = (double)left_max.top(); 
			} 
			else
			{ 
				right_min.push(x); 
				med = (double)right_min.top(); 
			} 
		} 

		// case3(right side heap has more elements) 
		else
		{ 
			if (x > med) 
			{ 
				left_max.push(right_min.top()); 
				right_min.pop(); 
				right_min.push(x); 
			} 
			else
				left_max.push(x); 

			med = (left_max.top() + right_min.top())/2.0; 
		} 

		cout<<med<<endl; 
	} 
} 

int main() 
{ 
	int arr[] = {5, 15, 10, 20, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printMedians(arr, n); 
} 
