#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>

// UNDIRECTED & UNWEIGHTED GRAPH 
class Graph {
	private:
		int nodes;
		map<int,list<int>> adj;

	public:

		Graph(int n, vector<Pair>&edges) {
			this->nodes = n;

			for(int i=0;i<edges.size();i++){
				int u = edges[i].first, v = edges[i].second;
				
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		// TC : O(N+E) 	&	SC : O(N+E) 
		vector<int> shortestPathBfs(int src, int dest) {
			queue<int> q;
			map<int,bool>visited;
			vector<int>parent(nodes);

			q.push(src);
			visited[src] = true;
			parent[src] = -1;
			
			while(!q.empty()) {
				int node = q.front();
				q.pop();

				for(int nbr : adj[node]) {

					// can avoid using visited map & instead check on parent array if nbr is visited or not
					if(!visited[nbr]) {
						visited[nbr] = true;
						parent[nbr] = node;
						q.push(nbr);
					}
				}
			}

			vector<int> ans;
			ans.push_back(dest);

			// Backtrack from dest to src using parent array
			while(src != dest && dest != -1) {
				dest = parent[dest];
				ans.push_back(dest);
			}
			
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main() {
	vector<Pair> edges = 
	{
		{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 7}, {3, 5}, {4, 7}, {5, 6}, {6, 7}
	};

	int n = 8;
	Graph g(8, edges);

	vector<int> ans = g.shortestPathBfs(0, 7);

	cout<<"Shortest Path using BFS : ";
	for(int ele : ans)
		cout<<ele<<" ";
	cout<<endl;
}
