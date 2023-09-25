#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(2^N) SC : O(N)

bool isPalind(string str , int i , int j)
{
    if(str[i]==str[j] && isPalind(str,i+1,j-1))
        return true;
    return false;
}

int lenMaxPalin(string str , int start, int end)
{
    if(start>end || start<0 || end>=str.length())
        return 0;

    if(start==end)
        return 1;

    if(str[start]==str[end] && isPalind(str,start+1,end-1))
        return end-start+1;

    return max(lenMaxPalin(str,start,end-1) , lenMaxPalin(str,start+1,end));
}

// Bottom Down TC : O(N^2)

int lenMaxPalinBU(string str , int size)
{
    bool ans[size][size];

    for(int strlen=2;strlen<=size;strlen++)      // Length of substring
    {
        for(int i=0; i<size-strlen ; i++)     // All subtrings of given length
        {
            int j = i + strlen-1;

            if(strlen==2)
                ans[i][j] = str[i]==str[j] ? true : false;

            else 
                ans[i][j] = str[i]==str[j] && ans[i+1][j-1] ? true : false;
        }
    }

    for(int j=size-1 ; j>=0 ; j--)
    {
        for(int i=0; i-j+size < size ; i++)
        {
            if(ans[i][j+i])
                return j-i+1;
        }
    }
    return ans[0][size-1];
}


/* --------------- NEWER APPROACH FOR SUBSEQUENCE --------------- */

// Similar to Longest Common Subsequence Problem 

int recursion(string str1, string str2, int i, int j) {

    if(i >= str1.size() || j >= str2.size())
        return 0;

    if(str1[i] == str2[j])
        return 1 + recursion(str1, str2, i+1, j+1);
    
    return max(recursion(str1, str2, i+1, j) , recursion(str1, str2, i, j+1));
}

int topDown(string str1, string str2, int i, int j, vector<vector<int>> &dp) {

    if(i >= str1.size() || j >= str2.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(str1[i] == str2[j]) 
        dp[i][j] = 1 + topDown(str1, str2, i+1, j+1, dp);
    
    else 
        dp[i][j] = max(topDown(str1, str2, i+1, j, dp) , topDown(str1, str2, i, j+1, dp));

    return dp[i][j];    
}


int bottomUp(string str1, string str2) {

    vector<vector<int>> dp (str1.size()+1, vector<int> (str2.size()+1, 0));
    
    for(int i=str1.size()-1; i>=0; i--){
        for(int j=str2.size()-1; j>=0; j--){

            if(str1[i] == str2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    return dp[0][0];
}

int bottomUpOptimized(string str1, string str2) {

    vector<int> curr(str1.size()+1,0);
    vector<int> next(str2.size()+1,0);
    
    for(int i=str1.size()-1; i>=0; i--){
        for(int j=str2.size()-1; j>=0; j--){

            if(str1[i] == str2[j])
                curr[j] = 1 + next[j+1];
            else
                curr[j] = max(next[j], curr[j+1]);
        }

        next = curr;
    }
    
    return next[0];
}

int main()
{
    string str = "abca";
    cout<<lenMaxPalin(str,0,str.length()-1)<<endl;
    cout<<lenMaxPalinBU(str,str.length())<<endl;


    // Newer approach for subsequence

    string str1 = "bbbabd", str2 = str1;
    reverse(str2.begin(), str2.end());

    cout<<"Length of longest palindromic subsequence using recursion : "<<recursion(str1, str2, 0, 0)<<endl;

    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
    cout<<"Length of longest palindromic subsequence using top down : "<<topDown(str1, str2, 0, 0, dp)<<endl;

    cout<<"Length of longest palindromic subsequence using bottom up : "<<bottomUp(str1, str2)<<endl;
    cout<<"Length of longest palindromic subsequence using bottom up optimized : "<<bottomUpOptimized(str1, str2)<<endl;
}
