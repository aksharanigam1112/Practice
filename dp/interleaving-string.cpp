// Given three strings A, B and C. 
// Check whether C is an interleaving of A and B. 
// if it contains all characters of A and B and order of all characters is preserved.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Top Down Recursion TC : O(2^N)
bool interleave(string s1, string s2, string s3, int i, int j, int k)
{
    if(i>=s1.length() && j>=s2.length() && k>=s3.length())
        return true;
    
    if(s1[i] == s3[k])
        return interleave(s1,s2,s3,i+1,j,k+1);
    else if (s2[j]==s3[k])
        return interleave(s1,s2,s3,i,j+1,k+1);
    else
        return false;
}

// Bottom Up TC :  O(M*N)   SC : O(M*N)
bool interleaveBU(string A, string B, string C) 
{ 
	int M = A.length(), N = B.length(); 

	bool dp[M+1][N+1]; 
    memset(dp, false, sizeof(dp)); 

	if(M+N != C.length()) 
		return false; 

	for(int i=0; i<=M; i++) 
    { 
		for(int j=0; j<=N; j++) 
        { 
			if (i == 0 && j == 0) 
				dp[i][j] = true; 

			// A is empty & character matches with B
			else if (i == 0 && B[j - 1] == C[j - 1]) 
					dp[i][j] = dp[i][j - 1]; 

			// B is empty & character matches with A
			else if (j == 0 && A[i - 1] == C[i - 1]) 
					dp[i][j] = dp[i - 1][j]; 
			 
            // It matches A but not B
			else if ( A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
				dp[i][j] = dp[i - 1][j]; 

            // It matches B but not A
			else if ( A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
				dp[i][j] = dp[i][j - 1]; 

            // It matches both A and B
			else if ( A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; 
		} 
	} 
	return dp[M][N]; 
} 


int main()
{
    string s1 = "XXY" , s2 = "XXZ" , s3 = "XXXXZY";
    cout<<"Can the string be formed ? "<<(interleave(s1,s2,s3,0,0,0) ? "Yes" : "No")<<endl;
    cout<<"Can the string be formed ? "<<(interleaveBU(s1,s2,s3) ? "Yes" : "No")<<endl;
}