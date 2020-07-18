#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void search(int *arr, int target, int start, int end, int *ans,int count)
{
    if(start>end || count>=2)
        return ;

    int mid = (start+end)/2;

    if(arr[mid]==target)
    {
        ans[count++] = mid;
        search(arr,target,start,mid-1,ans,count);
        // search(arr,target,mid+1,end,ans,count);
    }
    else if(arr[mid]<target)
        search(arr,target,mid+1,end,ans,count);
    else
        search(arr,target,start,mid-1,ans,count);
}

int main()
{
    int arr[] = {7,7,7,8,8,10};
    int end = sizeof(arr)/sizeof(arr[0])-1 ;
    int ans[end+1];
    memset(ans,-1,sizeof(ans));

    search(arr,8,0,end,ans,0);
    cout<<"Start pos :- "<<ans[1]<<"\nEnd pos :- "<<ans[0]<<endl;
}