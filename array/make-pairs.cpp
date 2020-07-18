#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   
        int n, m,c,count=0;
        cin>>n>>m>>c;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(x!=y)
                {
                    if(arr[y] == m*arr[x] + c)
                        count++;
                }
            }
        }
        cout<<count<<endl;
    
}