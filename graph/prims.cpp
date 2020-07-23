#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

typedef pair<int,int> Pair ;

class Graph
{
    private : 
        map<int,vector<Pair>>adj;
        int V,cost;

		void print(vector<int>dist)
		{
			cout<<"MST from Source : "<<endl; 
			for (int i=0; i<V; i++) 
			{
				cout<<i<<" : "<<dist[i]<<endl;
		 		cost+=dist[i];
			}
			cout<<"Min cost Required : "<<cost<<endl;
		}

	public : 

        Graph(int nodes)
        {
            V = nodes;
            cost=0;
        }

        void addEdge(int u, int v, int wt) 
        { 
            adj[u].push_back(make_pair(v, wt)); 
            adj[v].push_back(make_pair(u, wt)); 
        } 

		// TC : O(E Log V)
		void prims(int src)
		{
			priority_queue<Pair, vector<Pair>, greater<Pair>>p;
			map<int,bool>visited;
			vector<int>dist(V,INT_MAX);

			p.push(make_pair(0,src));
			dist[src]=0;
			
			while(!p.empty())
			{
				int u = p.top().second;
				visited[u]=true;
				p.pop();

				for(auto it : adj[u])
				{
					int v = it.first;
					int weight = it.second;

					if(dist[v] > weight && visited[v]==false)
					{
						dist[v] = weight;
						p.push(make_pair(dist[v],v));
					}
				}
			}
			print(dist);
		} 
};

int main() 
{ 
	Graph g(7);
	
	g.addEdge(0,1,15);
	g.addEdge(0,2,12);
    g.addEdge(0,4,10);

	g.addEdge(1,2,4);
	g.addEdge(1,4,20);
    g.addEdge(1,6,9);
    g.addEdge(1,5,12);

	g.addEdge(2,3,7);
	g.addEdge(2,4,5);
	
    g.addEdge(3,5,5);
    g.addEdge(3,4,2);
	
    g.addEdge(4,5,3);
    g.addEdge(4,6,6);

	g.prims(0);

} 
