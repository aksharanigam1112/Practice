// Given a string, determine if it is a palindrome, 
// considering only alphanumeric characters and ignoring cases.
#include<iostream>
#include<string>
using namespace std;

bool palindrome(string str)
{
    if(str.length()==0 || str.length()==1)
        return true;

    int s=0, l=str.length()-1;
    string cap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string low = "abcdefghijklmnopqrstuvwxyz";

    while(s<=l)
    {
        while(cap.find(str[s])==string::npos && low.find(str[s])==string::npos)
            s++;
        while(cap.find(str[l])==string::npos && low.find(str[l])==string::npos)
            l--;
        
        if(abs(str[s]-str[l]) == 32 || abs(str[s]-str[l]) == 0)
        {
            s++;
            l--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str = ".,";
    cout<<"Is valid palindrome of not : "<<(palindrome(str)?"Yes":"No")<<endl;
}