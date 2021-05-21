// Given an integer n, find a sequence that satisfies all of the following:
// 1) The integer 1 occurs once in the sequence.
// 2) Each integer between 2 and n occurs twice in the sequence.
// 3) For every integer i between 2 & n, the distance between the two occurrences of i is exactly i.
// Return the lexicographically largest sequence.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(int n, int index, vector<int>&ans, set<int>&hash)
{
    if(hash.size() == 0) 
        return true; 

    if(hash.size()>0 && index >= ans.size())
        return false;

    for (int j=n; j>=1; j--) 
    {
        int dist = j == 1 ? 0 : j;
        
        if (hash.count(j) && ans[index] == -1 && index+dist<ans.size() && ans[index+dist] == -1)
        {
            ans[index] = ans[index+dist] = j; 
            hash.erase(j);

            if(solve(n,index+1,ans,hash)) 
                return true; 
            
            ans[index] = ans[index+dist] = -1;
            hash.insert(j);
        }
        else
        {
            if(solve(n,index+1,ans,hash))
                return true;
        }
    }
    return false;
}


vector<int> constructDistancedSequence(int n) 
{
    vector<int>ans(1+2*(n-1),-1);
    set<int>hash;

    for(int i=n;i>=1;i--)
        hash.insert(i);

    solve(n,0,ans,hash);

    return ans;
}

int main()
{
    int n = 5;
    vector<int> ans = constructDistancedSequence(n);

    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
}