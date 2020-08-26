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

int main()
{
    string s1 = "XXY" , s2 = "XXZ" , s3 = "XXZXXXY";
    cout<<"Can the string be formed ? "<<(interleave(s1,s2,s3,0,0,0) ? "Yes" : "No")<<endl;
}