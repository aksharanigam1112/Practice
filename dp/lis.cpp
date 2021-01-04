// Longest increasing subsequence Non-DP
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(NlogN)    SC : O(N)
int findLISLength(int arr[], int n)
{
    set<int>hash;
 
    for(int i=0;i<n;i++)
    {
        if(hash.find(arr[i]) != hash.end()) 
            continue;
        
        auto ret = hash.insert(arr[i]);
        
        // cout<<*ret.first<<" "<<ret.second<<endl;
    
        set<int>::iterator it;
        if(ret.second)
            it = ret.first;
 
        // if element is not inserted at the end, then delete next
        // greater element from set
        if(++it != hash.end())
            hash.erase(it);
    }
    return hash.size();
}
 
int main()
{
    int arr[] = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout<<"Length of longest increasing subsequence : "<<findLISLength(arr, n)<<endl;
}