// You are given a 2D array adjacentPairs of size n-1 where each adjacentPairs[i] = [ui, vi] 
// The pairs can appear in any order.
// Return the original array 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>>adjList;

void makePair(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void print()
{
    for(auto i : adjList)
    {
        cout<<"For : "<<i.first<<" -> ";
        for(auto it : i.second)
        {
            cout<<it<<" , ";
        }
        cout<<endl;
    }
}

void dfs(int u, map<int,bool>&visited,vector<int>&ans)
{
    for(auto it : adjList[u])
    {
        if(!visited[it])
        {
            visited[it] = true;
            ans.push_back(it);
            dfs(it,visited,ans);
        }
    }
}

int startNode()
{
    for(auto it : adjList)
    {
        if(it.second.size()==1)
            return it.first;
    }
}


vector<int> restoreArray(vector<vector<int>>& pairs) 
{
    for(int i=0;i<pairs.size();i++)
        makePair(pairs[i][0],pairs[i][1]);

    print();

    int source = startNode();
    
    vector<int>ans;
    map<int,bool>visited;

    ans.push_back(source);
    visited[source] = true;
    dfs(source,visited,ans);
    return ans;    
}

int main()
{
    vector<vector<int>>arr = {{4,-2},{1,4},{-3,1}};
    vector<int>ans = restoreArray(arr);

    cout<<"Restored Array : ";
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}