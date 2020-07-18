#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int curr_sum=arr[0] , max_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        curr_sum = max(arr[i] , curr_sum+arr[i]);
        max_sum = max(max_sum , curr_sum);
    }
    cout<<max_sum<<endl;
}