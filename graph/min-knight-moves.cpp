// Given a chessboard, find the shortest distance (minimum number of steps) 
// taken by a knight to reach a from source to destination. Consider 8X8 board 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int> 
#define N 8

struct Node {
	int r, c, dist;

	Node(int row, int col, int d=0){
		r = row;
		c = col;
		dist = d;
	}
};

class Graph{ 
private:
	map<Pair, bool> visited;
	queue<Node> q;

	int row[N] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	int col[N] = { -1, 1, 1, -1, 2, -2, 2, -2 };
	
	bool isValid(int x, int y) {
		return x>=0 && x < N && y>=0 && y < N && !visited[{x,y}];
	}

public:	

	int findShortestKnightDistance(Node src, Node dest) {
		q.push(src);
		visited[{src.r, src.c}] = true;

		while(!q.empty()) {
			Node node = q.front();
			q.pop();

			if(node.r == dest.r && node.c == dest.c) 
				return node.dist;

			for(int i=0;i<N;i++) {
				int newR = node.r + row[i];
				int newC = node.c + col[i];

				if(isValid(newR, newC))
					q.push(Node{newR, newC, node.dist+1}); 
			}
		}

		return INT_MAX;
	}
};

int main() {
	Graph g;

    Node src = {0, 0};
    Node dest = {5, 5};
 
    cout<<"The minimum number of steps required by knight : "<<g.findShortestKnightDistance(src, dest)<<endl;
}
