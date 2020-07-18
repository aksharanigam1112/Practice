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

    void dfs(int src)
    {
        stack<int> s;
        map<int,bool> visited;

        s.push(src);
        visited[src]=true;

        while(!s.empty())
        {
            int ele = s.top();
            cout<<ele<<" ";
            s.pop();

            for(int nbr : adj[ele])
            {
                if(!visited[nbr])
                {
                    s.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout<<endl;
    }

    void dfs_recur(int v , map<int,bool>&visited)
    {
        visited[v] = true; 
        cout<<v<<" "; 
  
        for (int i : adj[v])       // Iterate over the list of v node
        {    
            if (!visited[i]) 
                dfs_recur(i, visited);
        } 
    }

    void dfs_main(int src)
    {
        // Mark all the vertices as not visited 
        map<int,bool> visited; 
        for (auto p :  adj) 
        {
            visited[p.first] = false; 
        }
    
        dfs_recur(src, visited); 
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

    cout<<"DFS Recursive :- ";
    g.dfs_main(0);

    cout<<"\nDFS Stack :- ";
    g.dfs(0);
}