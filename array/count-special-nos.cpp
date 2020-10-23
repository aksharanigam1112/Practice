// You have been an array. Return the Count of special numbers in an array. 
// A number is said to be special if it is divisible by at least one other element of the array.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int divisibilityCheck(int arr[], int n) 
{ 

	unordered_set<int> s; 
	int max_ele = INT_MIN,count=0;

	for(int i = 0; i < n; i++) 
    { 
		s.insert(arr[i]); 
        max_ele = max(max_ele, arr[i]); 
	} 

	// Storing the array multiples that are present in s in res 
	unordered_set<int> res; 
	for (int i = 0; i < n; i++) 
    { 
		if (arr[i] != 0) 
        { 
            for (int j = arr[i] * 2; j <= max_ele; j += arr[i]) 
            { 
				if (s.find(j) != s.end()) 
					res.insert(j); 
			} 
		} 
	} 

	unordered_map<int, int> mp; 
	for (int i = 0; i < n; i++) 
		mp[arr[i]]++; 

	for(auto it : mp) 
    { 
    	if (it.second >= 2) 
        { 
			if (res.find(it.first) == res.end()) 
            { 
				// If frequency is greater than 1 and 
				// the number is not divisible by any other number 
				int val = it.second; 

				while (val--) 
					count++;
			} 
		} 

		// If frequency is greater than 1 and the number 
		// is divisible by any other number 
		if (res.find(it.first) != res.end()) 
        { 
			int val = it.second; 
			while (val--) 
				count++;
		} 
	} 
	return count;
} 

int main() 
{ 
	int arr[] = {1,2,3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout<<"No. of special nos : "<<divisibilityCheck(arr, n)<<endl; 
} 
