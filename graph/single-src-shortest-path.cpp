// Distance calculated by level order traversal is the shortest for unweighted graph

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private: 
    map<int,list<int>>adj;

    void print(map<int,int>dist,int source)
    {
        cout<<"Node Distance"<<endl;
        for(auto src : dist)
        {
            if(src.first != source)
                cout<<src.first<<"\t"<<src.second<<endl;
        }
    }

    public:

    void addEdge(int u , int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void shortestPathBFS(int src)
    {
        queue<int> q;
        // Store the distance of the visited node from src
        map<int,int>dist;

        for(auto node_pair :adj)
        {
            int node = node_pair.first;
            dist[node] = INT_MAX;
        }
        
        q.push(src);
        dist[src]=0;

        while(!q.empty())
        {
            int ele = q.front();
            q.pop();

            for(int nbr : adj[ele])
            {
                if(dist[nbr]==INT_MAX)
                {
                    // cout<<nbr<<" ";
                    q.push(nbr);
                    dist[nbr] = dist[ele]+1;
                }
            }
        }

        print(dist,src);
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

    int src = 4;

    cout<<"Shortest Path from "<<src<<" to all other nodes :- "<<endl;
    g.shortestPathBFS(src);
}