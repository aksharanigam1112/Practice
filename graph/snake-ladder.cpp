// Min no. of dice (1-6 deterministic) throws req to reach the dest 36
// starting from the src. Find the shortest path as well.
// S - snakes , L - Ladders with their starting and ending pos
// No double turn for a 6

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
    }

    int shortestPathBFS(int src , int dest)
    {
        queue<int> q;
        map<int,int>dist, parent;

        for(auto node_pair :adj)
        {
            int node = node_pair.first;
            dist[node] = INT_MAX;
        }
        
        q.push(src);
        dist[src]=0;
        parent[src] = src;

        while(!q.empty())
        {
            int ele = q.front();
            q.pop();

            for(int nbr : adj[ele])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[ele]+1;
                    parent[nbr] = ele;
                }
            }
        }
        
        // print(dist,src);
        int temp  = dest;
        cout<<"\nPath : ";
        while(temp!=src)
        {
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        return dist[dest];
    }
};


int main()
{
    int board[50] = {0};

    // Snakes and ladders 
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    // Add edges to the graph
    Graph g;
    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j = i+dice;
            j+=board[j];

            if(j<=36)
                g.addEdge(i,j);
        }    
    }
    g.addEdge(36,36);

    cout<<"Minimum distance :- "<<g.shortestPathBFS(0,36)<<endl;

}