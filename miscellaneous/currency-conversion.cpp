// Find best exchange rate from currency1 to currency2
// https://leetcode.com/problems/evaluate-division/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<string ,string>
#define GPair pair<string, double>

class Graph{
private:
    map<string, list<GPair>> adjList;
    map<string, bool> visited;  


    void addEdge(string u, string v, double w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, 1/w});
    }

    double dfs(string src, string dest, double baseRate) {
        if(src == dest)
            return baseRate; 

        visited[src] = true;
        double minRate = INT_MAX;
        
        for(auto nbr : adjList[src]) {

            if(visited[nbr.first] == true)
                continue;

            double currRate = dfs(nbr.first, dest, nbr.second);
            minRate = min(minRate, currRate);
        }

        return baseRate * minRate;
    }

public:

    double currencyRate(vector<Pair> arr, vector<double> values, string src, string dest) {

        for(int i=0; i<arr.size(); i++)
            addEdge(arr[i].first, arr[i].second, values[i]);

        if(adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end())
            return -1;

        if(src == dest)
            return 1;

        return dfs(src, dest, 1);
    }
};


int main() {
    vector<Pair> arr = {
        {"USD", "JPY"}, {"JPY", "GBP"}, {"USD", "AUD"}, {"GBP", "THB"}, {"THB", "AUD"}
    };

    vector<double> values = {110, 0.0070, 1.45, 80, 0.0135};

    Graph g;

    cout<<"Best currency conversion rate : "<<g.currencyRate(arr, values, "GBP", "AUD")<<endl;
}
