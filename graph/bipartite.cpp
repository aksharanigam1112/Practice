// Given a graph having 0 based index. Check whether the graph is bipartite or not.
// If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, 
// it is called a bipartite graph.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int> 

class Graph {
	private :
	int nodes;
	map<int, list<int>> adj;
	vector<int> colours;

	bool bfs(int src) {
		queue<int> q;
		q.push(src);
		colours[src] = 0;

		while(!q.empty()) {
			int node = q.front();
			q.pop();

			for(int nbr : adj[node]) {
				
				if(colours[nbr] == -1) {
					q.push(nbr);
					colours[nbr] = !colours[node];
				} 
				// If nbr is already visited but has a different colour than what we are trying, 
				// then it means two adjacent nodes have same colours, hence not bipartite
				else if(colours[nbr] == colours[node])
					return false;
			}
		}
		return true;
	}

	bool dfs(int src) {
		
		for(int nbr : adj[src]) {

			if(colours[nbr] == -1) {
				colours[nbr] = !colours[src];
				if (!dfs(nbr))
					return false;
			}

			else if (colours[nbr] == colours[src])
				return false;
		}

		return true;
	}

	public:
	Graph(int n, vector<Pair>&edges) {
		this->nodes = n;

		for(int i=0;i<edges.size();i++) {
			int u = edges[i].first, v = edges[i].second;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		colours = vector<int>(n, -1);
	}

	void clearColours() {
		this->colours = vector<int>(this->nodes, -1);
	}

	bool isBipartiteBfs(int src) {
		for(int i=0;i<this->nodes;i++) {
	        if(colours[i] == -1) {
	            if(bfs(i) == false)
	                return false; 
	        }
	    }
	    return true; 
	}

	bool isBipartiteDfs(int src) {
		for(int i=0;i<this->nodes;i++) {
	        if(colours[i] == -1) {
	        	
	        	colours[i] = 0;
	            if(dfs(i) == false)
	                return false; 
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
	
	Graph g = Graph(10, edges);

	// vector<Pair> edges = {
	// 	{0,1}, {1,2}, {2,3}, {2,10}, 
	// 	{3,4}, {4,5}, {5,6}, {5,8},
	// 	{6,7}, {7,10}, {8,9}
	// };
	
	// Graph g = Graph(11, edges);

	cout<<"Is the Graph Bipartite using BFS : "<<(g.isBipartiteBfs(0) ? "Yes" : "No")<<endl;

	g.clearColours();

	cout<<"Is the Graph Bipartite using DFS : "<<(g.isBipartiteDfs(0) ? "Yes" : "No")<<endl;
}
