#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int remove(vector<int>&arr)
{
    int size = arr.size();
    int read = 0,write=-1;

    while(read<size)
    {
        if(write==-1)
        {
            write=0;
            arr[write] = arr[read++];
        }
        else if(arr[read] == arr[write])
            read++;
        else
            arr[++write] = arr[read++];
    }
    return write+1;
}

int main()
{
    vector<int>arr = {4,4,6,6,7,8,8,8,8,10,12,12,15,15};
    
    int len = remove(arr);
    
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
