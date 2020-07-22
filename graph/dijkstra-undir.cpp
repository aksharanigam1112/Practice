#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

class Graph
{
    private : 
        map<int,vector<pair<int,int>>>adj;
        int V;

		void print(vector<int>dist)
		{
			cout<<"Shortest Distance from Source : "<<endl; 
			for (int i=0; i<V; i++) 
				cout<<i<<" : "<<dist[i]<<endl; 
		}

	public : 

        Graph(int nodes)
        {
            V = nodes;
        }

        void addEdge(int u, int v, int wt) 
        { 
            adj[u].push_back(make_pair(v, wt)); 
            adj[v].push_back(make_pair(u, wt)); 
        } 

		// TC : O(E Log V)
		void dijkstra(int src) 
		{ 
			priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq; 

			vector<int> dist(V,INT_MAX); 

			// We add (distance,node) in the priority queue
			pq.push(make_pair(0, src)); 
			dist[src] = 0; 

			while (!pq.empty()) 
			{ 
				// extract the node
				int u = pq.top().second; 
				pq.pop(); 

				for (auto x : adj[u]) 
				{ 
					int v = x.first; 
					int weight = x.second; 

					if(dist[v] > dist[u] + weight) 
					{ 
						dist[v] = dist[u] + weight; 
						pq.push(make_pair(dist[v], v)); 
					} 
				} 
			} 
			print(dist);
		} 
};

int main() 
{ 
	Graph g(6);
	
	g.addEdge(0,1,5);
	g.addEdge(0,2,10);
	g.addEdge(1,2,2);
	g.addEdge(1,3,7);
	g.addEdge(2,3,8);
	g.addEdge(2,4,2);
	g.addEdge(2,5,8);
	g.addEdge(3,4,1);
	g.addEdge(4,5,4);

	g.dijkstra(0);

} 
