// 1760 Leetcode Medium
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) 
{
    int start=1,end = *max_element(nums.begin(),nums.end()),mid,ans;

    while(start<=end)
    {
        mid = (start+end)/2;
        int op=0;
        for(int i=0;i<nums.size();i++)
            op+= (nums[i]+mid-1)/mid - 1;
        
        if(op<=maxOperations)
        {
            ans = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return ans;
}


int main()
{
    vector<int>nums = {7,17};
    int maxOperations = 2;

    cout<<"Min Penalty : "<<minimumSize(nums,maxOperations)<<endl;
}   