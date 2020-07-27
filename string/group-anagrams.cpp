// Group anagrams together
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int generateKey(string word)
{
    map<int,int>hash;
    for(int i=0;i<word.length();i++)
    {
        hash[word[i]]++;
    }
    int sum=0;
    for(auto it : hash)
    {
        sum+=it.first * it.second;
    }
    return sum;
}

// TC : O(N*K) SC : O(N*K)
vector<vector<string>> groupAnagrams(vector<string>words)
{
    map<int,vector<int>>groups;

    for(int i=0;i<words.size();i++)
    {
        int key = generateKey(words[i]);
        groups[key].push_back(i);
    }
    
    vector<vector<string>>ans;
    for(auto it : groups)
    {
        vector<string>v;
        for(auto wd : it.second)
            v.push_back(words[wd]);
        ans.push_back(v);
    }
    return ans;
}

void print(vector<vector<string>>ans)
{
    for(auto v : ans)
    {
        cout<<"[ ";
        for(auto wrd : v)
            cout<<wrd<<", ";
        cout<<"]"<<endl;
    }
}

int main()
{
    vector<string>words = {"ACT","CAT","GOD","DOG","TAC","YES"};
    vector<vector<string>>ans = groupAnagrams(words);
    print(ans);
}