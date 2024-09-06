// Que : https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 1. Sliding window
int minSubarrayLength1(vector<int> &arr, int target) {

    int start = 0, sumSoFar = 0, minLen = INT_MAX;

    for(int end = 0; end<arr.size(); end++) {

        sumSoFar += arr[end];

        while(sumSoFar >= target) {
            minLen = min(minLen, end - start + 1);

            sumSoFar -= arr[start];
            start++;
        }
    }

    return minLen == INT_MAX ? 0 : minLen; 
}


// 2. Prefix sum
int minSubarrayLength2(vector<int>& arr, int target) {
    
    int n = arr.size(), minLen = INT_MAX;

    vector<int>prefixSum(n+1, 0);

    for (int i = 1; i <= n; i++) 
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    
    // We start from end because prefix sum has the greatest value at the end & will result in small subarray size
    // We consider only elements with prefix sum >= target, else the subarray with smaller sum is of no use
    for (int end = n; end >= 0 && prefixSum[end] >= target; end--) {

        int start = upper_bound(prefixSum.begin(), prefixSum.end(), prefixSum[end]-target) - prefixSum.begin();

        // cout<<"Upper bound for "<<prefixSum[end]-target<<" is at : "<<start<<" has prefixSum value : "<<prefixSum[start]<<endl;


        minLen = min(minLen, end - start + 1);
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}

int main() {
    // vector<int> arr = {2,3,1,2,4,3}; int target = 7; // ans : 2
    vector<int> arr = {1,2,3,4,5}; int target = 11; // ans : 3
    // vector<int> arr = {1,4,4}; int target = 4; // ans : 1
    // vector<int> arr = {1,1,1,1,1,1,1,1}; int target = 11;

    cout<<"Min subarray length with sum >= "<<target<<" using SlidingWindow is : "<<minSubarrayLength1(arr, target)<<endl;

    cout<<"Min subarray length with sum >= "<<target<<" using PrefixSum is : "<<minSubarrayLength2(arr, target)<<endl;

}
