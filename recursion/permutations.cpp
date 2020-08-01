// Given a collection of distinct integers, return all possible permutations.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permute(vector<int>arr,int index, vector<vector<int>>&ans)
{
    if(index==arr.size())
        ans.push_back(arr);
    
    for(int i=index;i<arr.size();i++)
    {
        swap(arr[index],arr[i]);
        permute(arr,index+1,ans);
        swap(arr[index],arr[i]);
    }
}

void print(vector<vector<int>>&ans)
{
    for(auto it : ans)
    {
        for(auto i : it)
            cout<<i<<" ";
        cout<<endl;
    }
}


int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<vector<int>>ans;
    permute(arr,0,ans);
    cout<<"All combinations : "<<endl;
    print(ans);
}