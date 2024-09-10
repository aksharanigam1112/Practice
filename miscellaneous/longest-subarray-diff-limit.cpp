// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int> 

int max(int a, int b) {
    return a > b ? a : b;
}

int longestSubarray(vector<int>& arr, int limit) {
    
    if(arr.size() <= 1)
        return arr.size();

    priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;
    priority_queue<Pair, vector<Pair>> maxHeap;

    int start = 0, maxLen = 0;

    for(int i=0; i<arr.size(); i++) {

        minHeap.push({arr[i], i});
        maxHeap.push({arr[i], i});

        // cout<<"MaxHeap top ele : "<<maxHeap.top().first<<endl;
        // cout<<"MinHeap top ele : "<<minHeap.top().first<<endl;

        Pair minEle = minHeap.top();
        Pair maxEle = maxHeap.top();

        // cout<<"Abs diff : "<<abs(maxEle.first - minEle.first)<<endl;
        
        while(abs(maxEle.first - minEle.first) > limit) {
            maxLen = max(maxLen, i-start);
            start++;

            while(minEle.second < start){
                minHeap.pop();
                minEle = minHeap.top();
            }

            while(maxEle.second < start){
                maxHeap.pop();
                maxEle = maxHeap.top();
            }
        }
    }


    return max(maxLen, arr.size()-start);
}

int main() {
    // vector<int> arr = {8,2,4,7}; int limit = 4; // ans : 2

    // vector<int> arr = {10,1,2,4,7,2}; int limit = 5; // ans : 4

    vector<int> arr = {4,2,2,2,4,4,2,2}; int limit = 0; // ans : 3

    cout<<"Longest subarray with diff between any two elements <= limit is : "<<longestSubarray(arr, limit)<<endl;
}
