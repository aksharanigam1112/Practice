// You are given a string. Find the lexicographically smallest palindrome 
// you can make using the string characters only. If you cannot print -1.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string palindrome(string str)
{
    // Store in descending order
    map<char,int,greater<char>>count;

    char ans[str.length()];

    // Count the frequencies of each character
    for(int i=0;i<str.length();i++)
        count[str[i]]++;
    
    int found = 0,mid,n = str.length(),i;
    char ch;

    // Find the charater that repeats odd times
    for(auto it : count)
    {
        if(it.second%2!=0)
        {
            found++;
            ch = it.first;
        }   
    }

    // If more than one character occurs odd no. of times then not possible
    if(found>1)
        return "-1";

    // For odd length string 
    if(n%2!=0)
    {
        mid = n/2;
        ans[mid] = ch;
        count[ch]--;

        i = mid-1;
    }
    // For even length string
    else
    {
        mid = n/2 -1;
        i = mid;
    }

    // TC : O(N) 
    for(auto it : count)
    {
        while(it.second>0 && i>=0)  // Amortized cost
        {
            ans[i] = it.first;
            ans[n-1-i] = it.first;
            it.second-=2;
            i--;
        }
    }

    string palindrome = "";

    for(auto it : ans)
        palindrome+=it;
    
    return palindrome;
}

int main()
{
    string str = "malayalam";
    cout<<"Lexicographic Palindrome String : "<<palindrome(str)<<endl;
}