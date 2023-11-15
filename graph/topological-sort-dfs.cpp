// For edge starting from u to v
// In topological sort u is always followed by v unlike dfs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    map<int, list<int>> adj;
    map<int, bool> visited;
    stack<int> s;

    void dfs(int src) {
        visited[src] = true;

        for(int nbr : adj[src]) {
            if(!visited[nbr])
                dfs(nbr);
        }
        s.push(src);
    }

    void print() {
        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSort() {
        for(auto i : adj){
            if(!visited[i.first])
                dfs(i.first);
        }

        print();
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

    g.topologicalSort();
}
