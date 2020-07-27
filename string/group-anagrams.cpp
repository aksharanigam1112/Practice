// Group anagrams together
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


// TC : O(N*K*LogK) SC : O(N*K)
vector<vector<string>> groupAnagrams(vector<string>words)
{
    map<string,vector<string>>hash;
 
    for(int i=0;i<words.size();i++)
    {
        string str,temp;
        str = words[i];
        temp = str;
        sort(str.begin(),str.end());
        hash[str].push_back(temp);
    }
 
   vector<vector<string>>ans;

    for(auto wd : hash)
        ans.push_back(wd.second);
    
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
    vector<string>words = {"ACT","CAT","DOG","GOD","TAC","DUH","ILL"};
    vector<vector<string>>ans = groupAnagrams(words);
    print(ans);
}