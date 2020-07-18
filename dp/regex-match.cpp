// Regex match 
// '.' ==> any characterr match
// '*' ==> 0 or more occurances of the character previous to it
#include<iostream>
#include<string>
using namespace std;

bool match(string pattern, string str)
{
    int m = str.length();
    int n = pattern.length();
    bool dp[m+1][n+1];

    for(int i=1;i<=m;i++)
        dp[i][0] = false;
    
    for(int i=1;i<=n;i++)
        dp[0][i] = false;

    dp[0][0] = true;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1]==pattern[j-1] || pattern[j-1]=='.')
                dp[i][j] = dp[i-1][j-1];

            else if(pattern[j-1]=='*')
            {
                if(str[i-1]==pattern[j-2] || pattern[j-2]=='.')
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-2];
            }
            else
                dp[i][j] = false;
        }
    }
    cout<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[m][n];
}

int main()
{
    string pat = "ab*c.", str="acm";
    cout<<"Regex match or Not : "<<(match(pat,str)?"Yes" : "No")<<endl;
}