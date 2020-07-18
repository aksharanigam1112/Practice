#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    int nodes;
    // Map between the scr and pair of dest and weights
    map<string,list< pair<string,int>>> adj;
 
    public:
    Graph(int n)
    {
        this->nodes = n;
    }
    void addEdge(string u , string v , int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    void print()
    {
        for(auto p: adj)
        {
            string src = p.first;
            list<pair<string,int>> dest = p.second;

            cout<<"For node "<<src<<" :-";
            
            for(auto nbr : dest)
            {
                cout<<" ("<<nbr.first<<" "<<nbr.second<<")";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge("A","B",20);
    g.addEdge("B","D",30);
    g.addEdge("A","C",10);
    g.addEdge("C","D",40);
    g.addEdge("A","D",50);

    g.print();
}