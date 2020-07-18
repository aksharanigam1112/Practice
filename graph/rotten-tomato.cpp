// Given some rotten tomatoes, find the no. of days all the tomatoes will get rotten.
// Rotten tomoatoes only rot, in 4 directions (neighbours)
#include<iostream>
#include<bits/stdc++.h>
#define RS 4
#define CS 5
using namespace std;

void findRotten(int arr[RS][CS], queue<int>&bfs,map<int,bool>&visited)
{
    for(int i=0;i<RS;i++)
    {
        for(int j=0;j<CS;j++)
        {
            if(arr[i][j]==0)
            {
                bfs.push(i*CS+j);
                visited[i*CS+j]=true;
            }
        }
    }
}

int rotten(int arr[RS][CS])
{
    queue<int>bfs;
    map<int,bool>visited;

    findRotten(arr,bfs,visited);
    bfs.push(-1);
    int day=0;

    while(!bfs.empty())
    {
        int ele = bfs.front();
        bfs.pop();

        if(ele==-1)
        {
            if(!bfs.empty())
            {
                bfs.push(-1);
                day++;
            } 
        }
        else
        {
            int R = ele/CS, C=ele%CS;
                
            // UP
            if(R-1>=0 && arr[R-1][C]!=0 && visited.find((R-1)*CS+C)==visited.end())
            {
                bfs.push((R-1)*CS+C);
                visited[(R-1)*CS+C] = true;
            }

            // DOWN
            if(R+1<RS && arr[R+1][C]!=0 && visited.find((R+1)*CS+C)==visited.end())
            {
                bfs.push((R+1)*CS+C);
                visited[(R+1)*CS+C] = true;
            }

            // LEFT 
            if(C-1>=0 && arr[R][C-1]!=0 && visited.find(R*CS+(C-1))==visited.end())
            {
                bfs.push(R*CS+(C-1));
                visited[R*CS+(C-1)] = true;
            }

            //RIGHT
            if(C+1<CS && arr[R][C+1]!=0 && visited.find(R*CS+(C+1))==visited.end())
            {
                bfs.push(R*CS+(C+1));
                visited[R*CS+(C+1)] = true;
            }
        }
    }
    return day;

}

int main()
{
    int arr[RS][CS];
    memset(arr,1,sizeof(arr));
    arr[0][0]=0;
    arr[1][1]=0;
    arr[2][4]=0;
    arr[3][0]=0;
    cout<<"No. of days required : "<<rotten(arr)<<endl;
}