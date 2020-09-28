#include <bits/stdc++.h>
using namespace std;
#define nodes 4
set<int> visited;
   vector<int> disc(nodes);
   vector<int> low(nodes);
   int t=0;
   vector<pair<int,int>> ret;
   


void print_vector(vector<pair<int, int> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "["<<v[i].first<<" "<<v[i].second<<"],";
   }
   cout << "]"<<endl;
}

   void dfs(int node, int par, vector<int> graph[]) 
   {
      if (visited.count(node))
        return;
      
      visited.insert(node);
      disc[node] = low[node] = t;
      t++;
      
      for (int x : graph[node]) 
      {
         if (x == par)
            continue;

         if (!visited.count(x)) 
         {
            dfs(x, node, graph);
            low[node] = min(low[node], low[x]);
            if (disc[node] < low[x]) 
               ret.push_back({ node, x });
         } 
         else
            low[node] = min(low[node], disc[x]);
      }
   }
   vector<pair<int,int>> criticalConnections(int n, vector<pair<int,int> >& v) 
   {
      disc.resize(n + 1);
      low.resize(n + 1);
    
      vector<int> graph[n + 1];
      for (int i = 0; i < v.size(); i++) 
      {
         int u = v[i].first;
         int w = v[i].second;
         graph[u].push_back(w);
         graph[w].push_back(u);
      }
      dfs(0, -1, graph);
      return ret;
   }

int main()
{

   vector<pair<int,int>> v = {{0,1},{1,2},{2,0},{1,3}};
   print_vector(criticalConnections(4,v));
}