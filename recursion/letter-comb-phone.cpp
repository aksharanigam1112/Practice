// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent.
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void phnLetter(map<char,string>&phn, string digits, int pos,string str,vector<string>&ans)
{
    for(auto it : phn[digits[pos]])
    {
        str.push_back(it);
        phnLetter(phn,digits,pos+1,str,ans);
        // cout<<str<<endl;
        if(str.length() == digits.length())
            ans.push_back(str);
        str.pop_back();
    }
}

int main()
{
    map<char,string>phn;
    phn.insert(make_pair('2',"abc"));
    phn.insert(make_pair('3',"def"));
    phn.insert(make_pair('4',"ghi"));
    phn.insert(make_pair('5',"jkl"));
    phn.insert(make_pair('6',"mno"));
    phn.insert(make_pair('7',"pqrs"));
    phn.insert(make_pair('8',"tuv"));
    phn.insert(make_pair('9',"wxyz"));

    string digits = "94";
    vector<string>ans;
    phnLetter(phn,digits,0,"",ans);

    cout<<"All possible combinations are : "<<endl;
    for(auto it : ans)
        cout<<it<<endl;
}