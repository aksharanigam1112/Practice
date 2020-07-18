#include<iostream>
#include<list>
using namespace std;

class Graph
{
    private :
    int nodes;
    // Array of list
    list<int>*adj;

    public :

    Graph(int n)
    {
        this->nodes = n;
        adj = new list<int>[n];
    }
    
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for(int i=0;i<nodes;i++)
        {
            cout<<"For node "<<i<<" : ";
            for(int j : adj[i])     //OR for(auto i = adj[i].begin() ; i!=adj[i].end() ; i++)
            {
                cout<<" "<<j;
            }
            cout<<endl;
        }
    }
};


int main()
{
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,3);

    graph.print();
}