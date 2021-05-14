#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int r, int c)
{
    if(i<0 || j<0 || i >=r || j>=c )
        return false;
    return true;
}

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
{
    int r = isWater.size(), c = isWater[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>> ans (r,vector<int>(c,0));

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(isWater[i][j]==1)
            {
                isWater[i][j] = -1;
                q.push({i,j});
            }
        }
    }

    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second, height = ans[i][j];
        q.pop();
        
        //  North
        if(isValid(i-1,j,r,c) && isWater[i-1][j]!=-1)
        {
            ans[i-1][j] = height+1;
            isWater[i-1][j] = -1;
            q.push({i-1,j});
        }
           
        // South
        if(isValid(i+1,j,r,c) && isWater[i+1][j]!=-1)
        {
            ans[i+1][j] = height+1;
            isWater[i+1][j] = -1;
            q.push({i+1,j});
        }
            
        // East
        if(isValid(i,j+1,r,c) && isWater[i][j+1]!=-1)
        {
            ans[i][j+1] = height+1;
            isWater[i][j+1] = -1;
            q.push({i,j+1});
        }
        
        // West
        if(isValid(i,j-1,r,c) && isWater[i][j-1]!=-1)
        {
            ans[i][j-1] = height+1;
            isWater[i][j-1] = -1;
            q.push({i,j-1});
        }
    }
    return ans;
}



int main()
{
    vector<vector<int>> isWater = {{0,1},{0,0}};
    vector<vector<int>> ans =  highestPeak(isWater) ;
        
    for(auto i : ans)
    {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
}