// Leetcode Medium - 1870
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minSpeedOnTime(vector<int>& dist, double hour) 
{
    int start = 1, end = 10000000, mid,ans=INT_MAX;

    while(start<=end)
    {
        mid = (start+end)/2;

        int i;
        double time=0;      
        for(i=0;i<dist.size()-1;i++)
            time+= ceil((double)dist[i]/mid);
        
        time+= (double)dist[i]/mid;

        if(time > hour)
            start = mid+1;
        else
        {
            ans = min(ans,mid);
            end = mid-1;
        }

        // cout<<"start : "<<start<<" mid : "<<mid<<" end : "<<end<<" time : "<<time<<" ans : "<<ans<<endl;
    }

    return ans==INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> dist = {1,3,2};
    double hour = 1.9;

    cout<<minSpeedOnTime(dist,hour)<<endl;
}