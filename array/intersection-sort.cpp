#include<iostream>
#include<bits/stdc++.h>
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

    sort(a,a+n);
    sort(b,b+n);

    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
        else if(a[i]<b[j])
            i++;
        else
            j++;
    }    
}