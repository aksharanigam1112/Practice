#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int remove(vector<int>&arr,int val)
{
    int write=-1,read=0;

    while(read<arr.size())
    {
        if(arr[read]!=val)
        {
            write ++;
            arr[write] = arr[read];
        }
        read++;
    }
    return write+1;
}

int main()
{
    vector<int>arr = {3,2,2,3};
    int val =  3;
    
    int len = remove(arr,val);
    
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
