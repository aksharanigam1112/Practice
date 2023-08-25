// KRUSKAL employs the use of disjoint sets with operations findParent() & Union()

// TC : O(ElogE + NlogN) where E = no. of edges & N = no. of nodes
// Theoretically findParent() & Union() take constant time ~O(1)
// Hence, TC : O(ElogE) (which is the time taken to sort the edges)

#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

struct Node {
	int src, dest, weight;

	Node(int u, int v, int w) {
		this->src = u;
		this->dest = v;
		this->weight = w;
	}
};

// Sort in ascending order
bool comp(Node n1, Node n2) {
	return n1.weight < n2.weight; 
}


// UNDIRECTED & WEIGHTED GRAPH 
class Graph {
	private:
		int nodes;

		vector<int> parent;
		vector<int> rank;

		int findParent(int node) {

			if (parent[node] == node)
				return node;

			// Using path compression to initialize the node to its parent instead of direct parent
			int p  = findParent(parent[node]);
			parent[node] = p;

			return p;
		}

		void unionSet(int u, int v) {
			u = findParent(u);
			v = findParent(v);

			if(rank[u] == rank[v]) {
				parent[v] = u;
				rank[u]++;
			} 

			// Smaller tree joins to the bigger tree 
			else if (rank[u] < rank[v]) 
				parent[u] = v;

			else 
				parent[v] = u;
		}

		

	public:

		Graph(int n) {
			this->nodes = n;
			parent.resize(n);
			rank.resize(n);

			// Every node is parent of itself with rank 0
			for(int i=0;i<this->nodes;i++){
				parent[i] = i;
				rank[i] = 0;
			}
		}

		
		int minimumSpanningTree(vector<Node>&edges) {
			// 1. Sort the edges based on their weight
			sort(edges.begin(), edges.end(), comp);
			
			int minWeight = 0;


			// 2. Remove the least weighted edge & find their parents
			// 			If diff parents then merge / union
			// 			else ignore

			for(auto node : edges) {

				int u = findParent(node.src);
				int v = findParent(node.dest);

				if(u != v) {
					minWeight += node.weight;
					unionSet(u, v);
				}

			}

			return minWeight;
		}

};

int main() {
	vector<Node> edges = 
	{
		Node(0, 1, 2), Node(0, 3, 1), Node(0, 4, 4),
		Node(1, 2, 3), Node(1, 3, 3), Node(1, 5, 7),
		Node(2, 3, 5), Node(2, 5, 8),
		Node(3, 4, 9)
	};

	int n = 6;
	Graph g(n);

	cout<<"Cost of minimum spanning tree using kruskal's algo : "<<g.minimumSpanningTree(edges)<<endl;
}
