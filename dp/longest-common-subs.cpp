#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(2^N)
int lcaBF(string s1, string s2, int i, int j)
{
    if(i<0 || j<0)
        return 0;
    if(s1[i]==s2[j])
        return 1+lcaBF(s1,s2,i-1,j-1);
    
    return max(lcaBF(s1,s2,i-1,j),lcaBF(s1,s2,i,j-1));
}

// Bottom Up TC : O(N*M) 
int lcaBU(string s1, string s2)
{
    int n = s1.length(), m=s2.length();
    int dp[n+1][m+1];

    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
    
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
                dp[i][j] = 1+dp[i-1][j-1];
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

/** ------------------------ NEWER APPROACHES ------------------------ **/

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

// TC : O(N*M) & SC : O(min(N,M))
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
    
    return curr[0];
}

int main()
{
    string str1 = "ABCDT",str2 = "TACAD";
    cout<<"Length of LCS BF:- "<<lcaBF(str1,str2,str1.length()-1,str2.length()-1)<<endl;
    cout<<"Length of LCS BU:- "<<lcaBU(str1,str2)<<endl;

    // Newer approaches : 

    cout<<"Length of LCS using recursion : "<<recursion(str1, str2, 0, 0)<<endl;

    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
    cout<<"Length of LCS using top down : "<<topDown(str1, str2, 0, 0, dp)<<endl;

    cout<<"Length of LCS using bottom up : "<<bottomUp(str1, str2)<<endl;
    cout<<"Length of LCS using bottom up optimized : "<<bottomUpOptimized(str1, str2)<<endl;
}
