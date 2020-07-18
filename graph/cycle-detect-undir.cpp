//Cycle detection for a undirected graph
//Check if the parent of the node is same as the nbr of the node or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    list<int>*adj;
    int v;

    public:
    
    Graph(int nodes)
    {
        this->v = nodes;
        adj = new list<int>[v];
    }

    void addEdge(int i,int j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    bool dfs(int node , bool *visited , int parent)
    {
        visited[node]=true;

        for(auto i : adj[node])
        {
            if(!visited[i])
            {
                bool cycle = dfs(i,visited,node);
                if(cycle)
                    return true;
            }
            else if(i!=parent)
                return true;
        }
        return false;
    }

    bool cycle()
    {
        bool *visited = new bool [v];
        for(int i=0;i<v;i++)
            visited[i] = false;

        return dfs(0,visited,-1);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    cout<<"Cycle detected or not :- "<< (g.cycle() ? "Yes" : "No" )<<endl;
}