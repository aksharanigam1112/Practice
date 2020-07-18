#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public : 
    map<int,list<int>>adj;

    void addEdge(int u , int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs_recur(int v , map<int,bool>&visited)
    {
        visited[v] = true; 

        for (int i : adj[v])      
        {    
            if (!visited[i]) 
                dfs_recur(i, visited);
        } 
    }

    int components()
    {
        map<int,bool> visited; 

        for (auto p : adj) 
        {
            visited[p.first] = false; 
        }

        int count=0;
        for(auto i : visited)
        {
            if(!visited[i.first])
            {
                count++;
                dfs_recur(i.first, visited); 
            }
        }
        return count;
    }

};

int main()
{
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    
    g.addEdge(4,5);
    g.addEdge(5,6);

    g.addEdge(7,7);

    cout<<"Connected Components :- "<<g.components()<<endl;
}