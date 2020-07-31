// Given n pairs of parentheses, 
// write a function to generate all combinations of well-formed parentheses.
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void add(char arr[], int size, vector<string>&ans)
{
    string str="";
    for(int i=0;i<size;i++)
        str+=arr[i];

    ans.push_back(str);
}

void allValidPNC(int n, int index, char arr[], int rightSoFar, vector<string>&ans)
{
    if(index==2*n)
        add(arr,2*n,ans);

    // Select Closing Bracket
    if(rightSoFar < index-rightSoFar)
    {
        arr[index] = ')';
        allValidPNC(n,index+1,arr,rightSoFar+1,ans);
    }
    // Select Opening Bracket
    if(index-rightSoFar<n)
    {
        arr[index] = '(';
        allValidPNC(n,index+1,arr,rightSoFar,ans);
    }
}

int main()
{
    int n=3;
    vector<string>ans;
    char arr[2*n];
    allValidPNC(n,0,arr,0,ans);
    cout<<"All possible combinations are : "<<endl;

    for(auto it : ans)
        cout<<it<<endl;
}