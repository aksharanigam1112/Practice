#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n] ;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int minsofar=arr[0],max=-9999;

    for(int i=1;i<n;i++)
    {
        int curr = arr[i]-minsofar;
        if(curr > max)
            max = curr;
        if(arr[i]<minsofar)
            minsofar = arr[i];
    }
    cout<<max;
}