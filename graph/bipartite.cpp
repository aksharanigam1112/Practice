// Given a graph having 0 based index. Check whether the graph is bipartite or not.
// If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, 
// it is called a bipartite graph.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int> 

class Graph {
	private :
	map<int, list<int>> adj;
	map<int, int> visited;

	public:
	Graph(vector<Pair>&edges) {
		for(int i=0;i<edges.size();i++) {
			int u = edges[i].first, v = edges[i].second;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	bool isBipartiteBfs(int src) {
		queue<int> q;
		q.push(src);
		visited[src] = 1;

		while(!q.empty()) {
			int node = q.front();
			q.pop();

			for(int nbr : adj[node]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = !visited[node];
				} 
				// If nbr is already visited but has a different colour that what we are trying, 
				// then it means two adjacent nodes have same colour=, hence not bipartite
				else {
					int colour = !visited[node];
					if(visited[nbr] != colour)
						return false;
				}
			}
		}
		return true;
	}
}; 

int main() {
	vector<Pair> edges = {
		{0,1}, {1,2}, {2,3}, {2,7}, 
		{3,4}, {4,5}, {5,6}, {5,8},
		{6,7}, {8,9}
	};

	// vector<Pair> edges = {
	// 	{0,1}, {1,2}, {2,3}, {2,10}, 
	// 	{3,4}, {4,5}, {5,6}, {5,8},
	// 	{6,7}, {7,10}, {8,9}
	// };

	Graph g = Graph(edges);

	cout<<"Is the Graph Bipartite using BFS : "<<(g.isBipartiteBfs(0) ? "Yes" : "No")<<endl;
}
