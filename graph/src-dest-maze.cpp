// Move from source to destination in Min no. of steps
// Hurdle ==> 0
#include<iostream>
#include<bits/stdc++.h>
#define N 6
using namespace std;

void generatePath(map<int,int>&visited,int si,int sj,int di,int dj)
{
    int row=di,col=dj;

    while(row!=si && col!=sj)
    {
        int ele = visited[row*N+col];
        row = ele/N;
        col = ele%N;
        // cout<<"("<<row<<","<<col<<") <- ";
    }
    // cout<<"\nSteps : ";
}



// BFS TC : O(N^2) SC : O(N^2)
int minSteps(int grid[N][N],int sr,int sc, int dr, int dc)
{
    queue<int>bfs;
    map<int,int>visited;
    bfs.push(sr*N+sc);
    bfs.push(-1);
    visited[sr*N+sc]=sr*N+sc;
    int dist=0;

    while(!bfs.empty())
    {
        int ele = bfs.front();
        bfs.pop();

        if(ele==-1)
        {
            if(!bfs.empty())
            {
                bfs.push(-1);
                dist++;
            }
        }
        else
        {
            int R = ele/N, C = ele%N;
            if(R==dr && C==dc)
            {
                generatePath(visited,sr,sc,dr,dc);
                return dist;
            }

            // UP
            if(R-1>=0 && grid[R-1][C]!=0 && visited.find((R-1)*N+C)==visited.end())
            {
                bfs.push((R-1)*N+C);
                visited[(R-1)*N+C] = R*N+C;
            }

            // DOWN
            if(R+1<N && grid[R+1][C]!=0 && visited.find((R+1)*N+C)==visited.end())
            {
                bfs.push((R+1)*N+C);
                visited[(R+1)*N+C] = R*N+C;
            }

            // LEFT 
            if(C-1>=0 && grid[R][C-1]!=0 && visited.find(R*N+(C-1))==visited.end())
            {
                bfs.push(R*N+(C-1));
                visited[R*N+(C-1)] = R*N+C;
            }

            //RIGHT
            if(C+1<N && grid[R][C+1]!=0 && visited.find(R*N+(C+1))==visited.end())
            {
                bfs.push(R*N+(C+1));
                visited[R*N+(C+1)] = R*N+C;
            }
        }
    }

    return -1;
}

int main()
{
    int matrix[N][N] = {{1,1,1,1,1,1},
                        {0,0,1,1,0,1},
                        {1,1,1,0,1,1},
                        {0,1,1,1,1,1},
                        {1,0,1,1,1,1},
                        {0,1,1,0,1,1}};

    int sr=3,sc=1,dr=2,dc=4;
    cout<<"Min stpes required : "<<minSteps(matrix,sr,sc,dr,dc)<<endl;
}