#include<iostream>
#include<string>
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

int main()
{
    string str1 = "ABCDT",str2 = "TACAD";
    cout<<"Length of LCS BF:- "<<lcaBF(str1,str2,str1.length()-1,str2.length()-1)<<endl;
    cout<<"Length of LCS BU:- "<<lcaBU(str1,str2)<<endl;
}