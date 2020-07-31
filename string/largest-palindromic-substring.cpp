#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE O(N^3)
// bool isPalindrome(string str , int start , int end)
// {
//     while(start<end)
//     {
//         if(str[start] != str[end])
//             return false;
//         start++;
//         end--;
//     }
//     return true;
// }

// int maxSizePalin(string str)
// {
//     int size = -1;
//     for(int i=str.length()-1;i>=0;i--)
//     {
//         for(int j=0;j<=i;j++)
//         {
//             if(isPalindrome(str,j,i))
//             {
//                 if(i-j+1 > size)
//                     size = i-j+1;
//             }
//         }
//     }
//     return size;
// }


//OPTIMIZED TO O(N^2)

int longestPalSubstr(string str)  
{  
    int maxLength = 1, start = 0;  
    int len = str.length();  
  
    int low, high;  
  
    for (int i = 1; i < len; ++i)  
    {  
        // Find the longest even length palindrome with center points as i-1 and i.  
        low = i - 1;  
        high = i;  
        while (low >= 0 && high < len && str[low] == str[high])  
        {  
            if (high - low + 1 > maxLength)  
            {  
                start = low;  
                maxLength = high - low + 1;  
            }  
            --low;  
            ++high;  
        }  
  
        // Find the longest odd length palindrome with center point as i  
        low = i - 1;  
        high = i + 1;  
        while (low >= 0 && high < len && str[low] == str[high])  
        {  
            if (high - low + 1 > maxLength)  
            {  
                start = low;  
                maxLength = high - low + 1;  
            }  
            --low;  
            ++high;  
        }  
    }
    cout<<str.substr(start,maxLength)<<endl;  
    return maxLength;  
}  


int main()
{
    string str = "abpklkpntrtz";
    // cout<<maxSizePalin(str)<<endl;
    cout<<"Longest Palindromic Substring is : "<<longestPalSubstr(str)<<endl;
    return 0;
}