#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    
    int max = -9999;
    for(int i=0;i<n;i++)
    {
        int count = mp.find(arr[i])->second;
        int a = arr[i]+1;
        if(mp.find(a)!=mp.end())
            count+= mp.find(a)->second;
        

        if(count>max)
            max = count;
    }
    cout<<max<<endl;
}