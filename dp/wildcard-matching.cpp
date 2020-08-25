// Given an input string (s) and a pattern (p), 
// implement wildcard pattern matching with support for '?' and '*'.
// ? ==> Matches any single character.
// * ==> Matches any sequence of characters (including the empty sequence).

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// Iterative Approach   TC : O(N)
bool isMatch1(string s, string p) 
{ 
    int i=0, j=0, stri=-1, mat=0;
    while(i<s.length())
    {
        if(j<p.length() and (s[i]==p[j] || p[j]=='?'))
        {
            i++;
            j++;
        }
        else if(j<p.length() and p[j]=='*')
        {
            stri=j;
            j++;
            mat=i;
        }
        else if(stri!=-1)
        {
            mat++;
            i=mat;
            j=stri+1;
        }
        else
            return false;
    }
    while(j<p.length() && p[j]=='*')
       j++;
    
    return j==p.length();        
}

// Bottom Up DP     TC : O(N^2)     &   SC : O(N)
bool isMatch2(string str, string pattern) 
{ 
    int n = str.length() , m = pattern.length();

	// empty pattern can only match with empty string 
	if (m == 0) 
		return (n == 0); 

	bool dp[n + 1][m + 1]; 
	memset(dp, false, sizeof(dp)); 

	dp[0][0] = true; 

	// Only '*' can match with empty string 
	for (int j = 1; j <= m; j++)
    { 
		if (pattern[j - 1] == '*') 
			dp[0][j] = dp[0][j - 1]; 
    }

	for (int i = 1; i <= n; i++) 
	{ 
		for (int j = 1; j <= m; j++) 
		{ 
			// Two cases if we see a '*' 
			// a) ‘*’ indicates an empty sequence. 
			// b) '*' character matches with ith character in input 
			if (pattern[j-1] == '*') 
				dp[i][j] = dp[i][j-1] || dp[i-1][j]; 

			// Current characters are considered as matching in two cases 
			// (a) current character of pattern is '?' 
			// (b) characters actually match 
			else if(pattern[j-1] == '?' || str[i-1] == pattern[j-1]) 
				dp[i][j] = dp[i - 1][j - 1]; 

			// If characters don't match 
			else 
                dp[i][j] = false; 
		} 
	} 
	return dp[n][m]; 
} 

// char str[] = "baaabab"; 
// char pattern[] = "*****ba*****ab"; 
// char pattern[] = "ba*****ab"; 
// char pattern[] = "ba*ab"; 
// char pattern[] = "a*ab"; 
// char pattern[] = "a*****ab"; 
// char pattern[] = "*a*****ab"; 
// char pattern[] = "ba*ab****"; 
// char pattern[] = "****"; 
// char pattern[] = "*"; 
// char pattern[] = "aa?ab"; 
// char pattern[] = "b*b"; 
// char pattern[] = "a*a"; 
// char pattern[] = "baaabab"; 
// char pattern[] = "?baaabab"; 
// char pattern[] = "*baaaba*"; 

int main()
{
    string str = "addb" , pattern = "a?*b*";

    cout<<"Do the string match1 ? "<<(isMatch1(str,pattern) ? "Yes" : "No")<<endl;
    cout<<"Do the string match2 ? "<<(isMatch2(str,pattern) ? "Yes" : "No")<<endl;
    
}

