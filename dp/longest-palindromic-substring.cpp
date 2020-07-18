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

int main()
{
    string str = "abca";
    cout<<lenMaxPalin(str,0,str.length()-1)<<endl;
    cout<<lenMaxPalinBU(str,str.length())<<endl;

}