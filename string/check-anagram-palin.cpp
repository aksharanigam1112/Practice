// Check for a given string if its anagram is a palindrome or not
// Similar to the question to check if the characters of a string can be 
// rearranged to form a palindrome string 
#include<iostream>
#include<string>
#include<map>
using namespace std;

// TC : O(N)    &   SC : O(N)
bool checkPalindrome(string str)
{
    map<char,int>hash;
    for(int i=0;i<str.length();i++)
        hash[str[i]]++;
    
    int odd=0;
    for(auto it : hash)
    {
        if(it.second%2==1)
            odd++;
        if(odd>1)
            return false;
    }    
    return true;
}

int main()
{
    string str = "geeksfgeeks";
    cout<<"Is anagram palindrome ? "<<(checkPalindrome(str) ? "Yes" : "No")<<endl; 
}