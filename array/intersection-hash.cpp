#include<iostream>
#include<bits/stdc++.h>
#include<bitset>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int a[n] , b[m];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    set<int>hs;
    
    for(int i=0;i<n;i++)
    {
        hs.insert(a[i]);
    }

    for(int i=0;i<m;i++)
    {
        if(hs.find(b[i])!=hs.end())
            cout<<b[i]<<" ";
    }
}