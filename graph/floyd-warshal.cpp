#include<iostream>
#define V 4
#define INF 999
using namespace std;

void print(int adj[V][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

// TC : O(V^3)
void floydWarshal(int adj[V][V])
{
    // Current node to be considered
    for(int i=0;i<V;i++)
    {
        // Source
        for(int j=0;j<V;j++)
        {
            // Destination
            for(int k=0;k<V;k++)
            {
                if(adj[j][k] > adj[j][i] + adj[i][k])
                    adj[j][k] = adj[j][i] + adj[i][k];
            }
        }
    }
    print(adj);
}

int main()
{
    int adj[V][V] = {{0,5,INF,10},
                    {INF,0,3,INF},
                    {INF,INF,0,1},
                    {INF,INF,INF,0}};
    cout<<"All source shortest distance : "<<endl;
    floydWarshal(adj);
}