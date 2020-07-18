// Check is S1 is Substring of S2. If yes, return its staring index of 1st match.
#include<iostream>
#include<string>
using namespace std;

// Brute force TC : O(n*m)
int checkSubBF(string str1, string str2)
{
    for(int i=0;i<=str1.length()-str2.length();i++)
    {
        int count=0;
        int k = i;
        for(int j=0;j<str2.length();j++)
        {
            if(str1[k]==str2[j])
            {
                count++;
                // cout<<str1[k]<<" == "<<str2[j]<<" "<<count<<endl;
                k++;
            }
            else
                break;
        }
        if(count==str2.length())
            return i+1;
    }
    return -1;
}

// KMP TC : O(m+n)
int KMP(string str, string pattern)
{
    int lps[pattern.length()];
    lps[0] = 0;
    
}

int main()
{
    string str = "abcdabcabcdf";
    string pattern = "adf";

    cout<<"Pattern found at :- "<<checkSubBF(str,pattern)<<endl;
}
