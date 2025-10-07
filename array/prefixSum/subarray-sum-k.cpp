#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxLengthSubarray(vector<int> arr, int target) {
    if(arr.empty())
        return -1;

    // [SumSoFar, StartIndex] mapping
    map<int, int> prefixSum;
    prefixSum[0] = -1;
    int maxLen = -1, sumSoFar = 0;

    for(int i=0; i<arr.size(); i++) {
        sumSoFar += arr[i];

        if(prefixSum.find(sumSoFar) == prefixSum.end())
            prefixSum[sumSoFar] = i;

        if(prefixSum.find(sumSoFar - target) != prefixSum.end()){
            int startIndex = prefixSum[sumSoFar - target];
            maxLen = max(maxLen, i-startIndex);

            cout<<"Sum found between : "<<startIndex+1<<" , "<<i<<endl;
        }
    }

    return maxLen;
}

int main() {
    // vector<int> arr = {10, 5, 2, 7, 1, -10, -1}; int sum = 15; // Ans : 6 -> [10, 5, 2, 7, 1, -10]

    vector<int> arr = { 5, 6, -5, 5, 3, 5, 3, -2, 0 }; int sum = 8; // Ans : 6 -> [-5, 5, 3, 5]

    int ans = maxLengthSubarray(arr, sum);
    cout<<"Max Length Subarray : "<<ans<<endl;
}
