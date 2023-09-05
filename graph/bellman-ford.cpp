// Given a source vertex s from a set of vertices V in a weighted directed graph 
// where its edge weights w(u, v) can be -ve, find the shortest path weights d(s, v) from source s 
// for all vertices v present in the graph. If the graph contains a negative-weight cycle, report it.
// If a graph contains a “negative cycle” (i.e, a cycle whose edges sum to a -ve value) that is reachable from the source, then there is no shortest path

#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
#define Pair pair<int,int>

// DIRECTED WEIGHTED GRAPH
class Graph {
    private : 
        vector<vector<int>>adj;

		void print(int src, vector<int>dist) {
			cout<<"Cost of shortest distance from Source : "<<src<<endl; 

			for (int i=0; i<this->nodes; i++) {
				if (src !=  i)
					cout<<src<<" -> "<<i<<" : "<<dist[i]<<endl; 
			}
		}

	public : 
		int nodes;

        Graph(int n){
            this->nodes = n;
        }

        void addEdge(int u, int v, int wt) { 
            adj.push_back({u,v,wt});
        } 

		// When Graph is connected 			: TC : O(E*V)		SC : O(V)
		// When Graph is unconnected 		: TC : O(E*(V^2))	SC : O(V)
		void bellmanFord(int src) 
		{ 
			vector<int>dist(nodes, INT_MAX);
			dist[src] = 0;

			// Relax all edges nodes - 1 times. A shortest path from src to any other
    		// vertex can have at-most nodes - 1 edges
		    for (int i=0; i<nodes-1; i++) {
		       for(auto it : adj) {
					int u = it[0], v = it[1], wt = it[2];
					

					if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
						dist[v] = dist[u] + wt; 
		       }
		    }

		    // Nth relaxation to check -ve cycle
		    for(auto it : adj) {
		    	int u = it[0], v = it[1], wt = it[2];
					
				if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
					return ; 
		    }

			print(src, dist);
		} 
};

int main() 
{ 
	Graph g(6);
	
	g.addEdge(0,1,5);
	g.addEdge(1,2,-2);
	g.addEdge(1,5,-3);	
	g.addEdge(2,4,3);
	g.addEdge(3,2,6);
	g.addEdge(3,4,-2);
	g.addEdge(5,3,1);
	
	g.bellmanFord(0);

} 
