// Given a source vertex s from a set of vertices V in a weighted digraph where all its edge weights w(u, v) are non-negative, 
// find the shortest path weights d(s, v) from source s for all vertices v present in the graph.

// NOTE : DIJKSTRA'S ALGO WORKS ONLY FOR NON -VE WEIGHTS

#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

class Graph
{
    private : 
        map<int,vector<pair<int,int>>>adj;

		void print(int src, vector<int>dist)
		{
			cout<<"Shortest Distance from Source : "<<src<<endl; 
			for (int i=0; i<V; i++) {
				if (src !=  i && dist[i] != INT_MAX)
					cout<<src<<" -> "<<i<<" : "<<dist[i]<<endl; 
			}
		}

	public : 
		int V;

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
			print(src, dist);
		} 
};

int main() 
{ 
	Graph g(5);
	
	g.addEdge(0,1,10);
	g.addEdge(0,4,3);
	g.addEdge(1,2,2);
	g.addEdge(1,4,4);
	g.addEdge(2,3,9);
	g.addEdge(3,2,7);
	g.addEdge(4,1,1);
	g.addEdge(4,2,8);
	g.addEdge(4,3,2);


	for(int i=0;i<g.V;i++)
		g.dijkstra(i);

} 
