// No. of ways to score R runs, in B balls with atmost W wickets 
// Input : 10,2,9
// Output : 2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Top Down 
int cricket(int r,int b,int w,vector<vector<vector<int>>>&dp)
{
    if(b<0 || r<0)
        return 0;
    if(b==0)
    {
        if(r==0)
            return 1;
        else
            return 0;
    }

    if(dp[r][b][w]!=-1)
        return dp[r][b][w];
    
    int ans=0;

    // 6 runs
    ans+=cricket(r-6,b-1,w,dp);
    ans = ans%1000000007;

    // 4 runs
    ans+=cricket(r-4,b-1,w,dp);
    ans = ans%1000000007;

    // 0 runs
    ans+=cricket(r,b-1,w,dp);
    ans = ans%1000000007;

    // Wicket
    ans+=cricket(r,b-1,w-1,dp);
    ans = ans%1000000007;

    return dp[r][b][w] = ans;
}

int main()
{
    int r = 6, b = 2, w = 9;
    vector<vector<vector<int>>>dp (r+1,vector<vector<int>>(b+1,vector<int>(w+1)));

    for(int i=0;i<=r;i++)
    {
        for(int j=0;j<=b;j++)
        {
            for(int k=0;k<=w;k++)
                dp[i][j][k] = -1;
        }
    }
    cout<<"No of ways are : "<<cricket(r,b,w,dp)<<endl;
}