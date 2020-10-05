// Find all the symmetric pairs from a given array of pairs of integers.
// Symmetric means if (x,y) exists in array then (y,x) also exists.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void symmetric(vector<pair<int,int>>arr)
{
    set<pair<int,int>>s;

    for(int i=0;i<arr.size();i++)
        s.insert(arr[i]);

    for(int i=0;i<arr.size();i++)
    {
        int x = arr[i].first;
        int y = arr[i].second;

        if(s.find({y,x}) != s.end())
        {
            cout<<"{"<<x<<","<<y<<"}  |  {"<<y<<","<<x<<"}"<<endl;
            s.erase({x,y});
            s.erase({y,x});
        }
    }
}

int main()
{
    vector<pair<int,int>>arr;
    arr.push_back({3,4});
    arr.push_back({1,2});
    arr.push_back({5,2});
    arr.push_back({7,10});
    arr.push_back({4,3});
    arr.push_back({2,5});

    cout<<"Symmetric Pairs : "<<endl;
    symmetric(arr);
}