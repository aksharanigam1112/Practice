// Given a binary matrix of N x M, containing at least a value 1. 
// The task is to find the distance of the nearest 1 in the matrix for each cell. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>
#define Vector vector<int>

class Graph {
	public : 
		vector<Vector> adj;
		int Rows, Cols;

		map<Pair,bool> visited;

		Graph(int r, int c) {
			this->Rows = r;
			this->Cols = c;
		}

		void print(vector<Vector>&arr) {
			for(int i=0;i<Rows;i++) {
				for(int j=0;j<Cols;j++)
					cout<<arr[i][j]<<" ";
				cout<<endl;
			}
		}

		// TC : O(N*M) 	& SC : O(N*M)
		void nearest1Distance() {
			vector<Vector> distance(Rows, Vector(Cols, 0));
			queue<Pair> q;

			for(int i=0;i<Rows;i++) {
				for(int j=0;j<Cols;j++) {
					if(adj[i][j] == 1 && !visited[{i,j}]) {
						q.push({i,j});
						visited[{i,j}] = true;
					}
				}
			}

			while(!q.empty()) {
				Pair node = q.front();
				q.pop();

				int i = node.first, j = node.second;
				
				// LEFT
				if(j-1 >= 0 && !visited[{i,j-1}]) {
					q.push({i,j-1});
					distance[i][j-1] = distance[i][j]+1;
					visited[{i,j-1}] = true;
				}

				// RIGHT
				if(j+1 < Cols && !visited[{i,j+1}]) {
					q.push({i,j+1});
					distance[i][j+1] = distance[i][j]+1;
					visited[{i,j+1}] = true;
				}

				// TOP
				if(i-1 >= 0 && !visited[{i-1,j}]) {
					q.push({i-1,j});
					distance[i-1][j] = distance[i][j]+1;
					visited[{i-1,j}] = true;
				}

				// BOTTOM
				if(i+1 < Rows && !visited[{i+1,j}]) {
					q.push({i+1,j});
					distance[i+1][j] = distance[i][j]+1;
					visited[{i+1,j}] = true;
				}
			}

			print(distance); 
		}
};

int main() {
	vector<vector<int>> arr = {
		{0,0,0},
		{0,1,0},
		{1,0,1}
	};

	Graph g = Graph(3,3);
	g.adj = arr;

	cout<<"Original Matrix : "<<endl;
	g.print(g.adj);

	cout<<"Distance Matrix from the nearest 1 : "<<endl;
	g.nearest1Distance();
}
