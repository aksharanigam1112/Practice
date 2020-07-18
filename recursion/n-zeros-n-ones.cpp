#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(int *arr , int n)
{
    for(int i=0;i<2*n;i++)
        cout<<arr[i];
    cout<<endl;
}

void allCases(int *arr , int pos , int zerosofar , int n )
{
    if(pos == 2*n)
        print(arr , n);
    if(zerosofar < n)
    {
        arr[pos] = 0;
        allCases(arr,pos+1,zerosofar+1,n);
    }
    if(pos-zerosofar< n )
    {
        arr[pos] = 1;
        allCases(arr,pos+1,zerosofar , n);
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[2*n];
    allCases(arr,0,0,n);
}
