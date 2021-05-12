#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) 
{
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    int sum1 = accumulate(nums1.begin(),nums1.end(),0);
    int sum2 = accumulate(nums2.begin(),nums2.end(),0);
    
    if(sum1 < sum2)
    {
        swap(nums1,nums2);
        swap(sum1,sum2);
    }
    
    int diff = sum1-sum2, a = nums1.size()-1, b = 0, count = 0;
    
    if(diff == 0)
        return 0;

    while(diff!=0 && (a>=0 || b<nums2.size()))
    {
        int decr = a>=0 ? nums1[a]-1 : -1;
        int incr = b<nums2.size() ? 6-nums2[b] : -1;
        int mn;

        if(incr > decr)
        {
            mn = min(diff,incr);
            nums2[b]+=mn;
            b++;
        }
        else
        {
            mn = min(diff,decr);
            nums1[a] -= mn;
            a--;
        }
        diff -= mn;
        count++;
    }

    return diff == 0 ? count : -1;
}

int main()
{
    vector<int> nums1 = {6,6}, nums2 = {1};
    cout<<"Min no. operations : "<<minOperations(nums1,nums2)<<endl;
}