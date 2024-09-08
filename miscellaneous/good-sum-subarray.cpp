// https://leetcode.com/problems/continuous-subarray-sum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkGoodSubarray(vector<int> &arr, int k) {
    if(arr.size() < 2)
        return false;

    if(k == 1)
        return true;

    // Remainder , pos found
    map<int, int> hash;
    hash[0] = -1;

    int sumSoFar = 0;

    for(int i=0; i<arr.size(); i++){
        sumSoFar += arr[i];
        int rem = sumSoFar % k;

        if(hash.find(rem)!= hash.end()) {
            if(i - hash[rem] > 1)
                return true;
        }
        else
            hash[rem] = i;
        
    }
    
    return false;
}


int main() {
    vector<int> arr = {23, 2, 6, 4, 7}; int k=6; // ans : true

    // vector<int> arr = {23, 2, 6, 4, 7}; int k=13; // ans : false

    // vector<int> arr = {23,2,4,6,6}; int k=7; // ans : true

    // vector<int> arr = {5,0,0,0}; int k=3; // ans : true

    cout<<"Is good subarray with sum K : "<<checkGoodSubarray(arr, k)<<endl;
}
