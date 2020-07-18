// Given a collection of intervals, merge all overlapping intervals.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> merge(vector<pair<int,int>>&arr)
{
    vector<pair<int,int>> ans;
    
    for(auto i : arr)
    {
        bool flag = false;
        for(auto j=ans.begin();j!=ans.end();j++)
        {
            pair<int,int>p = *j;

            if( (i.first>=p.first && i.first<=p.second)  ||
                (p.first>=i.first && p.first<=i.second) )
            {
                cout<<"Merge : ("<<i.first<<","<<i.second<<") and ("<<p.first<<","<<p.second<<") =";
                p.first = min(p.first,i.first);
                p.second = max(p.second,i.second);
                cout<<" ("<<p.first<<","<<p.second<<")"<<endl;
                
                ans.erase(j);
                ans.push_back(p);
                
                flag = true;
                break;
            }
        }
        if(flag==false)
            ans.push_back(make_pair(i.first,i.second));
    }
    return ans;
}

int main()
{
    vector<pair<int,int>>arr;
    arr.push_back(make_pair(1,3));
    arr.push_back(make_pair(2,6));
    arr.push_back(make_pair(8,10));
    arr.push_back(make_pair(7,9));
    arr.push_back(make_pair(15,18));

    vector<pair<int,int>> ans = merge(arr);

    cout<<"Final intervals : "<<endl;
    for(auto it : ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}