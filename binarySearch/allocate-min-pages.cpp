#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValidConfig(long long int curr_ans, vector<int>pages, int students)
{
    int st = 1;
    long long int curr_pages = 0;

    for(int i=0;i<pages.size();i++)
    {
        if(curr_pages+pages[i]<=curr_ans)
            curr_pages+=pages[i];
        else
        {
            st++;
            curr_pages = pages[i];
        }    
    }
    return st<=students;    
}



int allocateMinPages(vector<int>pages, int students)
{
    long long int end = accumulate(pages.begin(),pages.end(),0),start=pages[pages.size()-1];
    int ans=0;

    while(start<=end)
    {
        long long int mid = (start+end)/2;
        // cout<<"Start : "<<start<<" end : "<<end<<" mid : "<<mid<<" ans : "<<ans<<endl;
        
        if(isValidConfig(mid,pages,students))
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
    vector<int>pages = {10, 20, 30, 40};
    int students = 2;

    cout<<"Min Pages : "<<allocateMinPages(pages,students)<<endl;
}