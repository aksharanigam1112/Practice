// For the given word find if it can be formed by concatenating dictionary words
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(L^L)
bool stringFromDict(string str, vector<string>&dict)
{
    if(str.length()==0)
        return true;
    for(int i=0;i<str.length();i++)
    {
        string prefix = str.substr(0,i+1);
        if(find(dict.begin(),dict.end(),prefix)!=dict.end())
        {
            if(stringFromDict(str.substr(i+1),dict))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<string> dict;
    dict.push_back("red");
    dict.push_back("basket");
    dict.push_back("ball");
    dict.push_back("all");
    dict.push_back("code");

    string word = "redbasketball";
    cout<<"Can be formed or not : "<<(stringFromDict(word,dict)?"YES" : "NO")<<endl;
}