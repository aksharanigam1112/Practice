// single source shortest path to all other nodes for a WEIGHTED GRAPH
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    map<int,list<pair<int,int>>>adj;
    
    public:
    Graph(int nodes)
    {
        v = nodes;
    }

    void addEdge(int u,int v, int weight)
    {
        adj[u].push_back(make_pair(v,weight));
        // adj[v].push_back(make_pair(u,weight));
    }

    void print()
    {
        for(auto p : adj)
        {
            cout<<p.first<<"-->";
            for(auto l : p.second)
            {
                cout<<l.first<<" , "<<l.second;
            }
            cout<<endl;
        }
    }

    void dijkstra(int src)
    {
        map<int,int>dist;

        for(auto j : adj)
        {
            dist[j.first] = INT_MAX;
        }

        // First parameter is distance bcoz in distance sorting happens
        // acc to the first parameter
        set<pair<int,int>>s;

        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            auto p = *(s.begin());
            int node = p.second;
            int nodeDist = p.first;

            s.erase(s.begin());

            // Iterate over nbrs of current node
            for(auto nbr : adj[node])
            {
                if(nodeDist + nbr.second < dist[nbr.first])
                {

                }
            }
        }

    }

};

int main()
{
    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(1,2,2);
    g.addEdge(1,3,8);
    g.addEdge(3,4,3);
    g.addEdge(4,5,2);
    g.addEdge(2,5,1);

    g.dijkstra(0);
}