// Create all possible anagrams of a given word
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void print(vector<char>ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
}

void anagrams(string word,map<char,int>&hash,vector<char>&ans)
{
    for(auto it : hash)
    {
        if(it.second!=0)
        {
            ans.push_back(it.first);
            hash[it.first]--;
            anagrams(word,hash,ans);

            if(ans.size() == word.length())
                print(ans);
            
            ans.pop_back();
            hash[it.first]++;
        }
    }
}

int main()
{
    string word = "ABA";
    map<char,int>hash;
    for(int i=0;i<word.length();i++)
        hash[word[i]]++;

    cout<<"Possible Anagrams are : "<<endl;
    vector<char>ans;
    anagrams(word,hash,ans);
}