// Minimum no. of steps to reach from 1 to 100, no double turn for a 6

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>
#define N 100

struct Node {
	int vertex, min_dist;
};


class Graph{
private: 
	queue<Node> q;
	map<int, bool> visited;

public:
	map<int, list<int>> adj;
	
	Graph(vector<Pair>&edges) {
        for (auto p : edges)
            adj[p.first].push_back(p.second);
    }

    int bfs(int src) {
    	q.push(Node{src,0});
    	visited[src] = true;

    	while(!q.empty()) {
    		Node node = q.front();
    		q.pop();

    		// Stop BFS if the last node is reached
	        if (node.vertex == N) {
	            return node.min_dist;
	        }
	 
	        
	        for (int nbr : adj[node.vertex]){
	            if (!visited[nbr]){
	            	
	                visited[nbr] = true;
	                q.push(Node{nbr, node.min_dist + 1});
	            }
        	}
    	}

    	return INT_MAX;
    } 
};


int findMinimumMoves(unordered_map<int,int> &ladder, unordered_map<int,int> &snake) {
	vector<Pair> edges;

	for(int i=0;i<N;i++) {

		for(int j=1;j<=6 && i+j<= N;j++) {
			int src = i;

			// update dest if there is any ladder or snake from the src
            int dest = (ladder[i + j] || snake[i + j]) ? (ladder[i + j] + snake[i + j]) : (i + j);
            edges.push_back({src, dest});
		}
	}

	Graph g = Graph(edges);
	return g.bfs(1);

}

int main() {
    unordered_map<int, int> ladder, snake;
 
    // insert ladders into the map
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;
 
    // insert snakes into the map
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;

    cout<<"Min no. of dice rolls to reach from 1 to 100 : "<<findMinimumMoves(ladder, snake)<<endl;
}
