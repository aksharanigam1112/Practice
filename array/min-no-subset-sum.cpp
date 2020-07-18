#include<iostream>
#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int arr1 [] = {1,1,3,4};

    int res=1;
    for(int i=0;i<4;i++)
    {
        if(arr1[i]<=res)
            res+=arr1[i];
    }
    cout<<res<<endl;

    res=1;
    int arr2[] = {1,2,5,10,20,40};
    for(int i=0;i<6;i++)
    {
        if(arr2[i]<=res)
            res+=arr2[i];
    }
    cout<<res<<endl;

}