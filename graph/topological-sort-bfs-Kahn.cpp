// Kahn's Algorithm states that for a directed acyclic graph
// there will always be a node with 0 in-degree and a node with 0 out-degree

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    list<int>*l;
    int v;

    public:
    Graph(int nodes)
    {
        this->v = nodes;
        l = new list<int>[v];
    }

    void addEdge(int i , int j)
    {
        l[i].push_back(j);
    }

    void topological()
    {
        int *indegree = new int [v];

        memset(indegree,0,sizeof(indegree));

        for(int i=0;i<v;i++)
        {
            for(auto y : l[i])
                indegree[y]++;
        }

        //bfs
        queue<int>q;
        //Find nodes with 0 indegree
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        //start removing elements from the queue
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            // iterate over the nbrs of that node & reduce indegree by 1
            for(auto nbr : l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
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

    g.topological();
    cout<<endl;
    return 0;
}