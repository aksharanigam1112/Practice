// Cycle detection for a directed graph. Check backage
// Store the path, bcoz a node which is already visited may or maynot be in the same path.
// hence if it is in the current path ==> Cycle detected else no cycle
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    list<int>*adj;
    int v;
    public:
    Graph(int nodes)
    {
        v = nodes;
        adj = new list<int>[v];
    }

    void addEdge(int i,int j)
    {
        adj[i].push_back(j);
    }

    bool cycle()
    {
        bool *visited = new bool[v];
        memset(visited,false,sizeof(visited));

        bool *path = new bool[v];
        memset(path,false,sizeof(path));

        return cycleCheck(0,visited,path);
    }

    bool cycleCheck(int src,bool*visited,bool*path)
    {
        visited[src] = true;
        path[src] = true;

        for(auto nbr : adj[src])
        {
            if(path[nbr])
                return true;
            else if(!visited[nbr])
            {
                bool cycle = cycleCheck(nbr,visited,path);
                if(cycle)
                    return true;
            }
        }

        path[src] = false;
        return false;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(3,4);
    // g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(5,6);

    cout<<"Cycle detected or not :- "<<(g.cycle()?"Yes" : "No")<<endl;
}