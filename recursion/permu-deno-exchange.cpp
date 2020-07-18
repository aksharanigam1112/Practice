#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int arr[6] , int notes[6][2])
{
    for(int i=0;i<6;i++)
    {
        // if(arr[i] !=0)
        //     cout<<notes[i][0]<< " * "<<arr[i] <<" = "<< notes[i][1]*arr[i] ;
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void waystoExchange(int selected[6] , int arr[6][2] , int index , int size , int sum)
{
    if(sum==0)
    {
        print(selected , arr);
        return;
    }
    if(sum<0 && index>=size)
        return;
    for(int i=0;i<arr[index][1];i++)
    {
        if(arr[index][0] * i > sum)
            return ;
        selected[index] = i;
        waystoExchange(selected,arr,index+1,size,sum-arr[index][0]*i);
        selected[index]=0;
    }
}

int main()
{
    int notes[][2] = {{1,20},{5,10},{10,12},{20,6},{40,8},{50,3}};
    int selected[6];
    memset(selected , 0 , 6);
    waystoExchange(selected , notes , 0,6,10);
}