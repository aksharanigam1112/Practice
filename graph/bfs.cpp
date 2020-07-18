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

    void bfs(int src)
    {
        queue<int> q;
        map<int,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            int ele = q.front();
            cout<<ele<<" ";
            q.pop();

            for(int nbr : adj[ele])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout<<endl;
    }

};

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);

    cout<<"BFS :-";
    g.bfs(0);
}