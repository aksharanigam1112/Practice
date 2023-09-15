// Find minimum length of subarray with K distinct integers
// where, 1 <= k <= array size 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Using concept of Sliding window
int minimumSize(vector<int> arr, int k) {
	map<int,int>hash;
	int left = 0, minLen = INT_MAX; 

	for(int right=0;right<arr.size();right++) {
		hash[arr[right]]++;
	
		while(hash.size() == k) {
			int windowLen = right - left + 1;
			minLen = min(minLen, windowLen);

			if(hash[arr[left]]-1 == 0)
				hash.erase(arr[left]);
			
			else
			    hash[arr[left]]--;
			
			left++;
		}
	}

	return minLen == INT_MAX ? -1 : minLen;
}

int main() {

	vector<int> arr = { 1, 1, 2, 2, 3, 3, 4, 5};
	int k = 3;

	cout<<"Minimum length of subarray with K distinct integers : "<<minimumSize(arr, k)<<endl;

}
