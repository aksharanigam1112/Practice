// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
private: 
    vector<int> arr;

public:
    int maximumInvitations(vector<int>& favorite) {
        this->arr = favorite;

        return max(maxCycle(), topologicalSort());
    }

    int max(int A, int B){
        if(A > B)
            return A;
        return B;
    }

    int maxCycle() {
        map<int, bool> vis;

        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {

            if (vis[i]) 
                continue;

            vector<int> cycle;
            int j = i;

            while (!vis[j]) {
                cycle.push_back(j);
                vis[j] = true;
                j = arr[j];
            }

            for (int k = 0; k < cycle.size(); ++k) {
                
                if (cycle[k] == j) {
                    ans = max(ans, cycle.size() - k);
                    break;
                }
            }
        }

        return ans;
    }

    int topologicalSort() {
        int n = arr.size();
        
        vector<int> indeg(n, 0);
        vector<int> dist(n, 1);

        for (int v : arr) 
            indeg[v]++;
        
        queue<int> q;

        for (int i = 0; i < n; ++i){
            if (indeg[i] == 0) 
                q.push(i);
        }


        while (!q.empty()) {
            int i = q.front();
            q.pop();

            dist[arr[i]] = max(dist[arr[i]], dist[i] + 1);
            
            if (--indeg[arr[i]] == 0) 
                q.push(arr[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (i == arr[arr[i]]) 
                ans += dist[i];
        
        return ans;
    }
};


int main() {
    vector<int> favorite = {2,2,1,2}; 

    // vector<int> favorite = {3,0,1,4,1}; 

    Graph g;

    cout<<"Max invitations : "<<g.maximumInvitations(favorite)<<endl;
}
