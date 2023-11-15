// Kahn's Algorithm states that for a directed acyclic graph
// there will always be a node with 0 in-degree and a node with 0 out-degree

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodes;
    map<int, list<int>> adj;
    
public:
    Graph(int n) {
        this->nodes = n;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSort() {
        vector<int> indegree(this->nodes, 0);

        for(auto it : adj) {
            for(int nbr : adj[it.first])
                indegree[nbr]++;
        }

        queue<int> q;
        
        // Find nodes with 0 indegree
        for(int i=0; i<this->nodes; i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(int nbr : adj[node]) {
                indegree[nbr]--;

                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        cout<<endl;
    }

};

int main()
{
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    g.topologicalSort();
}
