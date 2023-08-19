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
    map<int,bool>visited;

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
        map<int,bool>path;
        return cycleCheckDfs(0, path);
    }

    bool cycleCheckDfs(int src, map<int,bool>&path)
    {
        visited[src] = true;
        path[src] = true;

        for(auto nbr : adj[src])
        {
            if(path[nbr])
                return true;
            else if(!visited[nbr])
            {
                bool cycle = cycleCheckDfs(nbr,visited,path);
                if(cycle)
                    return true;
            }
        }

        path[src] = false;
        return false;
    }

    // Similar to Kahn's algorithm to print topological sort using BFS
    bool cycleCheckBfs() {
        queue<int>q;
        map<int,int> indegree;
        int count = 0;

        // Indegree
        for(int i=0; i<v; i++) {
            for(int j : adj[i])
                indegree[j]++;
        }

        // Push elements to queue iff the indegree = 0
        for(int i=0;i<v;i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(int nbr : adj[node]){
                
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(count == v)
            return false;

        return true;
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

    cout<<"Cycle detected or not using DFS :- "<<(g.cycle()?"Yes" : "No")<<endl;

    cout<<"Cycle detected or not using BFS :- "<<(g.cycleCheckBfs()?"Yes" : "No")<<endl;
}
