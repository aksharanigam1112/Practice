// Given a string, find the length of the longest substring without repeating characters
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// TC : O(N) & SC : O(N)
int longestSubstr(string str)
{
    int n = str.length();
    set<char>hash;

    int maxLen=0, start=0, i=0;
    while (start < n && i < n) 
    {
        if(hash.find(str[i]) == hash.end())
        {
            hash.insert(str[i++]);
            maxLen = max(maxLen, i-start);
        }
        else 
            hash.erase(str[start++]);
    }
    return maxLen;
}

int main()
{
    string str = "pwwkew";
    cout<<"Length of longest Substring without repetition : "<<longestSubstr(str)<<endl;
}