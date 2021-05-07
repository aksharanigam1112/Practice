// You are given 3 +ve nos : n, index, and maxSum
// You want to construct an array nums that satisfies the following conditions:
// 1) nums.length == n
// 2) nums[i] is a positive integer where 0 <= i < n.
// 3) abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
// 4) The sum of all the elements of nums does not exceed maxSum.
// 5) nums[index] is maximized.
// Return nums[index] of the constructed array.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int sum(long long int n)
{
    return n*(n+1)/2;
}

// mid also denotes the value at index
bool isValid(int n, long long int mid, int index, int maxSum)
{
    long long int total_sum = mid, val_index = sum(mid-1);
    int left = index, right = n-index-1;

    if(left<mid)
        total_sum += val_index-sum(mid-left-1);
    else
        total_sum += val_index+left-mid+1;    
    
    if(right < mid)
        total_sum += val_index-sum(mid-right-1);
    else
        total_sum += val_index+right-mid+1;    

    return (total_sum<=maxSum);
}


int maxValue(int n, int index, int maxSum)
{
    int start = 0, end = maxSum, ans;
   
    while(start<=end)
    {
        long long int mid = (end+start)/2;
        
        if(isValid(n,mid,index,maxSum))
        {
            ans = mid;
            start = mid+1;
        }
        else
            end = mid-1;    
    }
    return ans;
}


int main()
{
    int n=4,index=2,maxSum=6;
    cout<<"Max value at an index is : "<<maxValue(n,index,maxSum)<<endl;
}