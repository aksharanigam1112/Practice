#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>

class Graph {
	private: 
		int nodes;
		map<int, list<int>>adj;

	public:
		Graph(int n, vector<Pair> &edges) {
			this->nodes = n;

			for(int i=0;i<edges.size();i++) {
				int u = edges[i].first, v = edges[i].second;

				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		void print() {
			for(auto ele : adj) {
				cout<<"\tFor node "<<ele.first<<" : ";

				for(int nbr : ele.second)
					cout<<nbr<<" "; 

				cout<<endl;
			}
		}

		bool isCycleDfs(int src, int parent, map<int,bool>&visited) {
			visited[src] = true;

			for(int nbr : adj[src]) {

				// Not visited
				if(!visited[nbr]) {
					bool cycle = isCycleDfs(nbr, src, visited);

					if(cycle)
						return true;
				} 

				// visited but the nbr node is not the parent
				else if (nbr != parent)
					return true;
			}

			return false;
		}

		bool isCycleBfs(int src) {
			queue<int> q;
			map<int,int> visited;

			q.push(src);
			visited[src] = -1;

			while(!q.empty()) {
				int node = q.front();
				q.pop();

				for(int nbr : adj[node]) {

					// Not visited
					if(visited.find(nbr) == visited.end()) {
						q.push(nbr);
						visited[nbr] = node;
					}

					// Visited but the nbr node is not parent 
					else if(visited[node] != nbr) 
						return true;
				}
			}

			return false;
		}
};



int main() {
	vector<Pair> edges =
    {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {4, 8},
        {4, 9}, {3, 6}, {3, 7}, {6, 10}, {6, 11}, {5, 9}
        // edge {5, 9} introduces a cycle in the graph
    };

    int n = 12;
    map<int,bool>visited;

    Graph g = Graph(n, edges);

    cout<<"Adjacency list : "<<endl;
    g.print();

    cout<<"\nIs cycle present by DFS : "<<(g.isCycleDfs(0, -1, visited) ? "Yes" : "No")<<endl;
    cout<<"\nIs cycle present by BFS : "<<(g.isCycleBfs(0) ? "Yes" : "No")<<endl;
}
