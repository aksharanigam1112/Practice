#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

// Brute force TC : O(2^N)
int triangleBF(vector<vector<int>>v , int i , int j)
{
    if(i>=v.size())
        return MAX;
    if(i==v.size()-1 && j < v[i].size())
        return v[i][j];
    
    return v[i][j] +  min(triangleBF(v,i+1,j) , triangleBF(v,i+1,j+1));
}

// Bottom Up TC : O(N^2) SC : O(N^2)
int triangleBU(vector<vector<int>>v)
{
    int size = v[v.size()-1].size();
    int dp[size][size];

    // Fill 1st row
    for(int i=0;i<size;i++)
    {
        dp[0][i] = i==0 ? v[0][0] : MAX;
    }

    // Fill 1st col
    for(int i=1;i<v.size();i++)
    {
        dp[i][0] = v[i][0] + dp[i-1][0]; 
    }
    int min_sum=MAX;
    for(int i=1;i<v.size();i++)
    {
        for(int j=1;j<size;j++)
        {
            dp[i][j] = v[i][j] + min(dp[i-1][j-1] , dp[i-1][j]);
            if(i==v.size()-1)
                min_sum = min(min_sum , dp[i][j]);

        }
    }

    // cout<<endl;
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=0;j<size;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return min_sum;
}

int main()
{
    vector<vector<int>>v;

    vector<int> v1 = {2};
    vector<int> v2 = {3,4};
    vector<int> v3 = {6,5,7};
    vector<int> v4 = {4,1,8,3};
    
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    cout<<"Min sum to reach base of triangle BF :- "<<triangleBF(v,0,0)<<endl;
    cout<<"Min sum to reach base of triangle BU :- "<<triangleBU(v)<<endl;
}