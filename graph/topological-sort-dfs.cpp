// For edge starting from u to v
// In topological sort u is always followed by v unlike dfs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    map<int,list<int>>adj;

    void dfs(int src,map<int,bool>&visited,stack<int>&s)
    {
        visited[src]=true;
        for(int i : adj[src])
        {

            if(!visited[i])
                dfs(i,visited,s);
        }
        s.push(src);
    }

    void print(stack<int>&s)
    {
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    public:
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }
    void topological()
    {
        map<int,bool>visited;
        stack<int>s;

        for(auto i : adj)
            visited[i.first]=false;

        for(auto i : adj)
        {
            if(!visited[i.first])
                dfs(i.first,visited,s);
        }

        print(s);
    }
};

int main()
{
    Graph g;
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(0,0);
    g.addEdge(1,1);

    g.topological();
}