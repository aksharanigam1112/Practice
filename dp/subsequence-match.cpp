// No of sub-sequence of string 2 int string 1
#include<iostream>
#include<string>
using namespace std;

int subsequenceMatch(string str1, string str2)
{
    int dp[str2.size()+1][str1.size()+1];

    // Fill 1st col
    for(int i=0;i<=str2.size();i++)
        dp[i][0] = 0;

    // Fill 1st row
    for(int i=0;i<=str1.size();i++)
        dp[0][i] = 1;

    for(int i=1;i<=str2.size();i++)
    {
        for(int j=1;j<=str1.size();j++)
        {
            // cout<<"Letters compared : "<<str2[i-1]<<" & "<<str1[j-1]<<endl;
            if(str1[j-1]==str2[i-1])
                dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    // cout<<endl;
    // for(int i=0;i<=str2.size();i++)
    // {
    //     for(int j=0;j<=str1.size();j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[str2.size()][str1.size()];
}

int main()
{
    string str1 = "aabcbc", str2 = "abc";
    cout<<"No of sub-sequence matches : "<<subsequenceMatch(str1,str2)<<endl;
}