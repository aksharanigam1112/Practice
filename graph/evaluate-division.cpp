// Equations are given in the format A / B = k, 
// where A and B are variables represented as strings, and k is a real number
// Given some queries, return the answers. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private: 
    map<string,vector<pair<string,double>>>adj;

    void addEdge(string u, string v, double w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,1/w));
    }

    public :
    void convert(vector<vector<string>>eq,vector<double>val)
    {
        int k=0;
        for(auto it : eq)
        {
            addEdge(it[0],it[1],val[k]);
            k++;
        }
    }

    void print()
    {
        for(auto it : adj)
        {
            cout<<it.first<<" :- ";
            for(auto ele : it.second)
            {
                cout<<"("<<ele.first<<","<<ele.second<<") ";
            }
            cout<<endl;
        }
    }

    double DFS(string src, string dest, double division, map<string,bool>&visited)
    {
        if(src==dest)
            return division;

        for(auto it : adj[src])
        {
            if(!visited[src])
            {
                visited[src]=true;
                division*= it.second;
                double val = DFS(it.first,dest,division,visited);
                if(val!=-1.0)
                    return val;
                division/= it.second;
                visited[src] = false;
            }
        }
        return -1.0;
    }

    vector<double> ansAllQueries(vector<vector<string>>queries)
    {
        map<string,bool>visited;
        vector<double> answer;
        for(auto i:queries)
        {
            if(adj.find(i[0]) == adj.end() || adj.find(i[1]) == adj.end()) 
                answer.push_back(-1.0);
            else
                answer.push_back(DFS(i[0],i[1],1.0000,visited));
            visited.clear();
        }
        return answer;
    }

    void queryAns(vector<vector<string>>queries, vector<double>ans)
    {
        int k=0;
        for(auto i : queries)
        {
            cout<<i[0]<<" , "<<i[1]<<" = "<<ans[k]<<endl;
            k++;
        }
    }
};


int main()
{
    vector<vector<string>>eq,queries;
    vector<double>k;

    eq.push_back(vector<string>{"a","b"});
    eq.push_back(vector<string>{"b","c"});

    k.push_back(2.0);
    k.push_back(3.0);

    queries.push_back(vector<string>{"a","c"});
    queries.push_back(vector<string>{"a","a"});
    queries.push_back(vector<string>{"b","a"});
    queries.push_back(vector<string>{"a","x"});
    queries.push_back(vector<string>{"e","e"});

    Graph g;
    g.convert(eq,k);
    // g.print();

    vector<double> ans = g.ansAllQueries(queries);
    g.queryAns(queries,ans);

}