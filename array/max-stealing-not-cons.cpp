#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxStealing(int arr[] , int i, int len)
{
    if(i>=len)
        return 0;
    return (max(maxStealing(arr,i+2,len)+arr[i] , maxStealing(arr,i+1,len)));
}

int main()
{
    int arr[] = {20,5,3,15,4,2,25};
    int ans = maxStealing(arr,0,7);
    cout<<ans<<endl;
}