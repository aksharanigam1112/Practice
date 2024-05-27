// https://www.geeksforgeeks.org/atlantic-pacific-water-flow/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>

class Solution{

private:
    vector<vector<int>> arr;
    int rows;
    int cols;
    int x[4] = { 0, 0, -1, 1 }; 
    int y[4] = { 1, -1, 0, 0 }; 

    bool isSafe(int i, int j, map<Pair,bool> &visited){

        if(i < 0 || i >= rows || j < 0 || j >= cols || visited[{i,j}])
            return false;

        return true;
    }

    void bfs(queue<Pair> &q, map<Pair,bool> &visited) {

        while(!q.empty()) {
            Pair p = q.front();
            visited[p] = true;
            q.pop();

            for(int i=0; i<4; i++){
                int newX = p.first + x[i];
                int newY = p.second + y[i];

                if(isSafe(newX, newY, visited) && arr[newX][newY] >= arr[p.first][p.second]){
                    q.push({newX, newY});
                    visited[{newX, newY}] = true;

                }
            }
        
        }
    }


public:
    Solution(vector<vector<int>> a){
        arr = a;
        rows = a.size();
        cols = a[0].size();
    }

    int countCoordinates(){

        queue<Pair> pacific, atlantic;
        map<Pair, bool> visited1, visited2;

        // Direct connection to Pacific (Top) & Atlantic (bottom)
        for(int j=0; j<cols; j++){
            pacific.push({0, j});
            atlantic.push({rows-1, j});
        }

        // Direct connection to Pacific (left) & Atlantic (right)
        for(int i=0; i<rows; i++) {
            pacific.push({i, 0});
            atlantic.push({i, cols-1});
        }

        bfs(pacific, visited1);

        bfs(atlantic, visited2);

        int ans = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(visited1[{i,j}] && visited2[{i,j}])
                    ans++;
            }
        }

        return ans;
    }

};

int main() { 
    vector<vector<int> > arr
        = { { 1, 2, 2, 3, 5 }, 
            { 3, 2, 3, 4, 4 }, 
            { 2, 4, 5, 3, 1 }, 
            { 6, 7, 1, 4, 5 }, 
            { 5, 1, 1, 2, 4 } }; 


    Solution s(arr);        
  
    cout <<"No of coordinates where water flow to both pacific & atlantic : "
        <<s.countCoordinates()<<endl; 
    return 0; 
}
