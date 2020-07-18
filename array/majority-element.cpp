#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE O(N^2)
int majorBF(int arr[] , int len)
{
    int maxele = -1 , maxcount=0;
    for(int i=0;i<len;i++)
    {
        int count =0;
        for(int j=0;j<len;j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if(count>maxcount)
        {
            maxcount = count;
            maxele = arr[i];
        }
    }
    if(maxcount > len/2)
        return maxele;
    else
        return -999;
}

//Binary Search O(NLogN)
int majorBS(int arr[] , int len)
{
    int maxcount=0,maxele=-1;
    for(int i=0;i<len;i++)
    {
        int low = lower_bound(arr,arr+len,arr[i])-arr;
        int high = upper_bound(arr,arr+len,arr[i])-arr;
        int count = high-low+1; 
        if(count>maxcount)
        {
            maxcount = count;
            maxele = arr[i];
        }
    }
    if(maxcount>len/2)
        return maxele;
    else
        return -999;
}


//Hashing O(N^2) with SC O(N)

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 10}; 
    int ans = majorBF(arr , 7);
    if(ans != -999)
        cout<<"Majority Element (BF):- "<<ans<<endl;
    ans = majorBS(arr , 7);
    if(ans != -999)
        cout<<"Majority Element (BS):- "<<ans<<endl;
    return 0;
}