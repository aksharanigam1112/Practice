// Given a non-empty array of integers, return the k most frequent elements.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> topK(int arr[], int size, int k)
{
    vector<int>ans;
    map<int,int>hash;
    for(int i=0;i<size;i++)
    {
        hash[arr[i]]++;
    }
    
    // Max Heap
    priority_queue<pair<int,int>>pq;
    for(auto it : hash)
    {
        pq.push(make_pair(it.second,it.first));
        // cout<<it.first<<" "<<it.second<<endl;
    }

    while(k--)
    {
        pair<int,int> ele = pq.top();
        pq.pop();
        ans.push_back(ele.second);
    }
    return ans;
}

int main()
{
    int arr[] = {1,1,1,2,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>ans = topK(arr,size,2);
    cout<<"Top K elements are : "<<endl;
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl; 
}