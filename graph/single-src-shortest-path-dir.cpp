# Find shortest path from a source node to all other nodes, for a directed weighted graph

#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
#define Pair pair<int,int> 

struct Node {
	int src, dest, weight;

	Node(int u, int v, int w) {
		this->src = u;
		this->dest = v;
		this->weight = w;
	}
};

// DIRECTED & WEIGHTED GRAPH 
class Graph {
	private:
		int nodes;
		map<int,list<Pair>> adj;
		map<int,bool> visited;

		void dfs(int node, stack<int> &s) {
			visited[node] = true;

			for(auto nbr : adj[node]) {
				if(!visited[nbr.first])
					dfs(nbr.first, s);
			}

			s.push(node);
		} 	

	public:

		Graph(int n, vector<Node>&edges) {
			this->nodes = n;

			for(int i=0;i<edges.size();i++){
				int u = edges[i].src, v = edges[i].dest, w = edges[i].weight;
				
				adj[u].push_back({v, w});
			}
		}

		void shortestPathDfs(int src) {
			stack<int> s;
			vector<int> distance(this->nodes, INT_MAX);

			// Use topological sort to get the linear ordering 
			for(int i=0;i<nodes;i++) {
				if(!visited[i])
					dfs(i, s);
			}

			// Set distance to reach source node as 0
			distance[src] = 0;

			while(!s.empty()) {
				int top = s.top();
				s.pop();

				if(distance[top] != INT_MAX) {

					for(auto nbr : adj[top]) 
						distance[nbr.first] = min(distance[nbr.first], distance[top] + nbr.second);
					
				}
			}

			cout<<"Shortest path to all nodes from "<<src<<" : "<<endl;
			for(int i=0;i<distance.size();i++) {
				int d = distance[i];
				if(d != INT_MAX)
					cout<<"\t"<<i<<" = "<<d;
			}
			cout<<endl;	
		}
};

int main() {
	vector<Node> edges = 
	{
		Node(0, 1, 5), Node(0, 2, 3), Node(1, 2, 2), Node(1, 3, 6), Node (2, 3, 7),
		Node(2, 4, 4), Node(2, 5, 2), Node(3, 4, -1), Node(4, 5, -2)
	};

	int n = 6;
	Graph g(n, edges);

	g.shortestPathDfs(1);
	
}
