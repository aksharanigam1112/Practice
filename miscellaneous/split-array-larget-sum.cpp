// https://leetcode.com/problems/split-array-largest-sum/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int k, int mid) {
    int subSum = 0, sumCount = 1;

    for(int i=0; i<arr.size(); i++) {

        if(subSum + arr[i] <= mid)
            subSum += arr[i];
        
        else {
            sumCount++;

            if(sumCount > k || arr[i] > mid)
                return false;

            // Reinitialize for next subarray sum calculation 
            subSum = arr[i];
        }
    }

    return true;
}

int splitArray(vector<int> arr, int k){

    int left = *max_element(arr.begin(), arr.end()), right = accumulate(arr.begin(), arr.end(), 0);

    int ans = 0;

    while(left<=right){
        int mid = (left + right) / 2;

        cout<<"Range : ["<<left<<","<<right<<"]"<<endl;

        if(isPossible(arr, k, mid)){
            cout<<"\t\tAns found : "<<mid<<endl;
            ans = mid;
            right = mid-1;
        } 
        else
            left = mid + 1;
    }

    return ans;
}



int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2; // Ans = 18 => {7,2,5}, {10,8}

    // vector<int> arr = {1,2,3,4,5};
    // int k = 3; // Ans = 6 => {1,2,3}, {4}, {5}

    int ans = splitArray(arr, k);    
    cout<<"Minimized largest sum after splitting array : "<<ans<<endl;
}
