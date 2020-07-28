// Minimize the search cost of the BST
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Bottom Up TC : O(N^3)
int sum(int freq[], int i, int j)
{
    int s=0;
    for(int k=i;k<=j;k++)
        s+=freq[k];
    return s;
}

int searchCostBST(int ele[], int freq[], int size)
{
    int cost[size][size];

    for(int i=0;i<size;i++)
        cost[i][i] = freq[i];
    
    for(int L=2;L<=size;L++)
    {
        for(int i=0;i<=size-L;i++)
        {
            int j = i+L-1, min_cost=INT_MAX;

            for(int k=i;k<=j;k++)
            {
                int LC = i==k ? 0 : cost[i][k-1];
                int RC = j==k ? 0 : cost[k+1][j];
                int c = LC+RC+sum(freq,i,k-1)+sum(freq,k+1,j)+freq[k];  
                min_cost = min(min_cost,c);
            }
            cost[i][j] = min_cost;
        }
    }

    // cout<<endl;
    // for(int i=0;i<size;i++)
    // {
    //     for(int j=i;j<size;j++)
    //     {
    //         cout<<cost[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return cost[0][size-1];
}

int main()
{
    int ele[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int size = sizeof(ele)/sizeof(ele[0]);

    cout<<"Minimum search cost : "<<searchCostBST(ele,freq,size)<<endl;
}