// Given some rotten tomatoes, find the no. of days all the tomatoes will get rotten.
// Rotten tomoatoes only rot, in 4 directions (neighbours)
// Ques : https://leetcode.com/problems/rotting-oranges/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>

class Graph {
private: 
    int RS, CS;  
    vector<vector<int>> arr;
    queue<Pair>q;
    map<Pair, bool> visited;

    void findRotten(){
        
        for(int i=0;i<RS;i++){
            for(int j=0;j<CS;j++) {

                // Check for arr[i][j] == 2 => Rotten orange
                if(arr[i][j] == 2){
                    q.push({i,j});
                    visited[{i,j}] = true;
                }
            }
        }
    }

    bool isSafe(int i, int j){
        // Check for arr[i][j] == 1 => Fresh orange
        return i >= 0 && i < RS && j >= 0 && j < CS && arr[i][j] == 1 && !visited[{i,j}];
    }

    bool isAllRotten() {

        for(int i=0; i<RS; i++) {
            for(int j=0; j<CS; j++) {
                
                // Non-empty cell & not visited => Fresh orange exists
                if(arr[i][j] == 1 && !visited[{i,j}])
                    return false;
            }
        }

        return true;
    }

public:

    Graph(vector<vector<int>> arr){
        this->arr = arr;
        this->RS = arr.size();
        this->CS = arr[0].size();
    }

    int getDaysToRot(){
        
        findRotten();
        // This acts as a marker to count no of days elapsed in rotting
        q.push({-1,-1});
        int days = 0;

        while(!q.empty()){
            auto [R,C] = q.front();
            q.pop();
            // cout<<"Element popped : "<<R<<","<<C<<endl;

            if(R == -1 && C == -1 && !q.empty()){
                q.push({-1,-1});
                days++;
            }

            else {
                // UP
                if(isSafe(R-1, C)){
                    q.push({R-1,C});
                    visited[{R-1,C}] = true;
                }

                // DOWN
                if(isSafe(R+1, C)){
                    q.push({R+1,C});
                    visited[{R+1,C}] = true;
                }

                // LEFT 
                if(isSafe(R, C-1)){
                    q.push({R,C-1});
                    visited[{R,C-1}] = true;
                }

                // RIGHT
                if(isSafe(R, C+1)){
                    q.push({R,C+1});
                    visited[{R,C+1}] = true;
                }
            }
        }

        return isAllRotten() ? days : -1; 
    }
};


int main(){
    vector<vector<int>> arr = {
        {2,1,1},{1,1,0},{0,1,1}
    }; // Ans : 4

    // vector<vector<int>> arr = {
    //     {2,1,1},{0,1,1},{1,0,1}
    // }; // Ans : -1

    // vector<vector<int>> arr = {{0,2}}; // Ans : 0

    Graph g(arr);

    cout<<"No. of days taken to rot : "<<g.getDaysToRot()<<endl;
}
