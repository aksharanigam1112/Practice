// https://leetcode.com/problems/escape-the-spreading-fire/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>
#define Vector vector<int> 

class Solution {
private:
    int rows, cols;
    vector<Vector> arr;
    vector<Pair> directions = {{-1,0},{0,1},{1,0},{0,-1}};


    bool isSafe(int x, int y) {
        if(x>=0 && x<rows && y>=0 && y<cols)
            return true;
        return false;
    }

    
    void findFireDist(vector<Vector>&dis)
    {
        queue<Pair>q;

        // Bfs on fire
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                
                // Fire
                if(arr[i][j]==1){
                    q.push({i,j});
                    dis[i][j] = 0;
                }

                // Wall
                else if(arr[i][j]==2)
                    dis[i][j] = -1;
            }
        }

        int level = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [x,y] = q.front();
                q.pop();

                for(auto it : directions){
                    int newX = x+it.first;
                    int newY = y+it.second;

                    if(isSafe(newX, newY) && dis[newX][newY] == INT_MAX){
                        dis[newX][newY] = level;
                        q.push({newX,newY});
                    }
                }
            }
            level++;
        }
    }

    bool check(vector<Vector>&dis, int mid)
    {
        queue<Vector>q;
        map<Pair, bool> visited;

        q.push({0,0,mid});
        visited[{0,0}] = true;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it[0], y = it[1], cost = it[2];

            if(x == rows-1 && y == cols-1)
                return true;
            
            for(auto it : directions) {

                int newX = x+it.first;
                int newY = y+it.second;

                // Safe && not wall && not visited && new cost < current dist
                if(isSafe(newX, newY) && dis[newX][newY] != -1 && !visited[{newX,newY}] && 
                    cost+1 < dis[newX][newY] ) {
                        //|| (newX == rows-1 && newY == cols-1 && cost+1 <= dis[newX][newY])))
                    
                    q.push({newX,newY,cost+1});
                    visited[{newX, newY}] = true;
                }
            }
        }

        return false;
    }
    
public: 
    int maximumMinutes(vector<Vector>&mat) {
        this->rows = mat.size();
        this->cols = mat[0].size();
        this->arr = mat;
        
        vector<Vector>dis(rows, vector<int>(cols,INT_MAX));
        findFireDist(dis);
        
        int l=0, r=(rows*cols), ans=-1;
        
        while(l<=r){
            int mid=(l+r)/2;

            if(check(dis, mid)){
                l = mid+1;
                ans = mid;
            }
            else
                r = mid-1;
        }
        
        return ans == rows*cols ? 1e9 : ans;
    }
};

int main() {
    vector<Vector> mat = {
        {0,2,0,0,0,0,0},
        {0,0,0,2,2,1,0},
        {0,2,0,0,1,2,0},
        {0,0,2,2,2,0,2},
        {0,0,0,0,0,0,0}};

    // vector<Vector> mat = {{0,0,0,0},{0,1,2,0},{0,2,0,0}};

    // vector<Vector> mat = {{0,0,0},{2,2,0},{1,2,0}};

    Solution s;
    cout<<"Maximum minutes : "<<s.maximumMinutes(mat)<<endl;
}
