#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(N LogN) SC : O(N)
// Divide & Conquer
int mergeCount(int*arr, int start, int mid, int end, int *copy)
{
    if(start>=end)
        return 0;

    int lc = start, rc = mid,inc=0,k=start;

    while(lc<mid && rc<=end)
    {
        if(arr[lc]<=arr[rc])
        {
            copy[k++]=arr[lc];
            lc++;
        }
        else
        {
            copy[k++] = arr[rc];
            rc++;
            inc+=(mid-lc);
        }
    }
    while(lc<mid)
    {
        copy[k++] = arr[lc++];
    }
    
    while(rc<=end)
    {
        copy[k++] = arr[rc++];
    }

    for(int i=start;i<=end;i++)
        arr[i] = copy[i];
    return inc;
}


int inversionPair(int *arr, int start, int end, int *copy)
{
    if(start>=end)
        return 0;
    int mid = (start+end)/2;
    int LV = inversionPair(arr,start,mid,copy);
    int RV = inversionPair(arr,mid+1,end,copy);
    int across = mergeCount(arr,start,mid+1,end,copy);

    return LV+RV+across;
}

int main()
{
    int arr[] = {1,20,6,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int copy[size];
    cout<<"No of inversion pairs :- "<<inversionPair(arr,0,size-1,copy)<<endl;

}