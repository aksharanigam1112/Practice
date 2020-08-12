// Given a string, a partitioning of the string is a palindrome partitioning 
// if every substring of the partition is a palindrome. 
// Find the minimum no of cute required to make palindromic parttioning possible
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Similar to matrix chain multiplication

int partition(string str) 
{ 
	int n = str.length(); 

	int C[n];   // To store the partition value 
	bool P[n][n]; // To check if the substring is palindrome of not


	for(int i=0; i<n; i++)  
		P[i][i] = true; 


	for(int L=2; L<=n; L++) 
    { 
        // Starting index
		for(int i=0; i<n-L+1; i++) 
        { 
			int j = i+L-1; // Ending index 

			if (L == 2) 
				P[i][j] = (str[i] == str[j]); 
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
		} 
	} 

	for(int i=0; i<n; i++) 
    { 
		if(P[0][i] == true) 
			C[i] = 0; 
		else 
        { 
			C[i] = INT_MAX; 
			for(int j=0; j<i; j++) 
            { 
				if(P[j + 1][i] && 1 + C[j] < C[i]) 
					C[i] = 1 + C[j]; 
			} 
		} 
	} 
    return C[n - 1]; 
} 

int main()
{
    string str = "aabc";
    cout<<"Minimum cute required : "<<partition(str)<<endl;
}

