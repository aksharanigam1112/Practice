// Calculate number of subArrays with same number of 1 & 0, in a array having 1 & 0 only
// Also find the max len of subarray with equal no of 0's and 1's

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(N^2)

// Optimized TC : O(N) & SC : O(N)
int count(int arr[], int size)
{
    // sum -1 corresponds to index 0 of hash
    // sum 0 corresponds to index 1 of hash
    // sum 1 corresponds to index 2 of hash

    int hash[3];
    memset(hash,0,sizeof(hash));

    for(int i=0;i<size;i++)
        arr[i] = arr[i]==0 ? -1 : arr[i];
    
    int count=0, sum=0;

    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        hash[sum+1]++;
    }

    for(int i=0;i<3;i++)
    {
        if(hash[i]>1)
            count+= (hash[i]* (hash[i]-1)/2);
    }
    count+=hash[1];
    return count;
}

int maxLen(int arr[], int size)
{
    map<int,int> hash;

    int count=0, maxlen = 0;

   
    for(int i=0;i<size;i++)
    {
        count += (arr[i]==1 ? 1 : -1);

        if(hash.find(count)==hash.end())
            hash[count] = i;
        else 
        {
            maxlen = max(i-hash[count] , maxlen);
        }
        // cout<<count<<"  "<<hash[count]<<"  "<<maxlen<<endl;
    }
    return maxlen;
}

int main()
{
    int arr[] = {1,0,0,1,0,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"No. of subarrays possible  : "<<count(arr,size)<<endl;
    cout<<"Max Length of subarray : "<<maxLen(arr,size)<<endl;

}