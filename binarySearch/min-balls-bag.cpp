// 1760 Leetcode Medium
// Ques : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) {
    // Since we know the max penalty will be = the max balls in bag 
    // => we need to reduce this penalty i.e it  can we between 1 to max bag
    // Thus its a binary search 
    int start=1, end = *max_element(nums.begin(),nums.end()), ans;

    while(start<=end){
        int mid = (start+end)/2, op=0;

        // Loop through all the bags to check for operations required 
        // to reduce the penalty score.
        for(int i=0; i<nums.size(); i++)
            op += (nums[i]-1)/mid;
        
        if(op <= maxOperations){
            ans = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }

    return ans;
}


int main(){
    vector<int>nums = {7,17}; int maxOperations = 2; // Ans : 7

    // vector<int> nums = {2,4,8,2}; int maxOperations = 4; // Ans : 2

    // vector<int> nums = {9}; int maxOperations = 2; // Ans : 3

    cout<<"Min Penalty : "<<minimumSize(nums,maxOperations)<<endl;
}   
