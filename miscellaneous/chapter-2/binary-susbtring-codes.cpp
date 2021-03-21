// Given a binary string s and an integer k.
// Return true if every binary code of length k is a substring of s. Otherwise, return false.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(set<string>hash)
{
    for(auto it : hash)
        cout<<it<<endl;
}

bool hasAllCodes(string s, int k) 
{
    set<string>hash;

    if(s.length()<k)
        return false;
        
    for(int i=0; i<=s.size()-k;i++)
    {
        string sub = s.substr(i,k);
        
        if (hash.find(sub) == hash.end())
            hash.insert(sub);
    }
    
    print(hash);

    if (hash.size() == pow(2,k))
        return true;
    return false;
}

int main()
{
    cout<<"Has all binary codes ? "<<(hasAllCodes("00110",2) ? "YES" : "NO")<<endl;
}