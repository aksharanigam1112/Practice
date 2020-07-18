#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>arr, int i, int size)
{
    if(i>=size)
        return;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l>=size)
        return;

    int minEle = r>=size ? l:(arr[r]<arr[l]?r:l);

    if(arr[minEle]<arr[i])
    {
        swap(arr[minEle],arr[i]);
        heapify(arr,minEle,size);
    }
}

void print(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int ugly(int n)
{
    int k=1;
    vector<int>arr(0);
    int ele = 1,i=0;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);

    while(k<n)
    {   
        heapify(arr,0,arr.size());
        ele = arr[0];
        // Remove the min element
        swap(arr[0],arr[arr.size()-1]);
        arr.pop_back();
        heapify(arr,0,arr.size());

        print(arr);
        if(find(arr.begin(),arr.end(),2*ele)==arr.end())
            arr.push_back(2*ele);
        if(find(arr.begin(),arr.end(),3*ele)==arr.end())
            arr.push_back(3*ele);
        if(find(arr.begin(),arr.end(),5*ele)==arr.end())
            arr.push_back(5*ele);
        k++;
    }
    return arr[0];
}

int main()
{
    int n = 7;
    cout<<"Ugly number is : "<<ugly(n)<<endl;
}