// Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. 
// A ‘O’ (or a set of ‘O’s) is considered to be by surrounded by ‘X’ 
// if there are ‘X’ at locations just below, just above, just left and just right of it

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Vector vector<char>

class Graph {

	private: 
		int Rows, Cols;

		void dfs(int i, int j) {
			if(i<0 || i>=Rows || j<0 || j>=Cols || adj[i][j] != 'O')
				return;

			adj[i][j] = '#';

			dfs(i, j-1); 
			dfs(i, j+1);
			dfs(i-1, j);
			dfs(i+1, j);
		}


	public : 
		vector<Vector> adj;
		

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

		
		// TC : O(N*M) 	& SC : O(N)
		void surroundedMatrix() {

			// Start finding neigbours of boundary O's since they can never become `X`
			for (int i=0; i<Rows; i++) {
            	for (int j=0; j<Cols; j++) {
                	if ((i == 0 || i == Rows-1 || j == 0 || j == Cols-1) && adj[i][j] == 'O')
                    	dfs(i,j);
           		}
			}

			for(int i=0;i<Rows;i++) {
				for(int j=0;j<Cols;j++){

					if(adj[i][j] == 'O')
						adj[i][j] = 'X';

					else if (adj[i][j] == '#')
						adj[i][j] = 'O';
				}
			}

			print(adj);
		}
};

int main() {
	vector<Vector> arr = {
		{'X','O','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'},
	};

	Graph g = Graph(4,4);
	g.adj = arr;

	cout<<"Original Matrix : "<<endl;
	g.print(g.adj);

	cout<<"Surrounded X Region Matrix : "<<endl;
	g.surroundedMatrix();
}
