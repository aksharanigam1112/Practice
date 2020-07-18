// check if 1 string is rotation of the other
#include<iostream>
#include<string>
using namespace std;

bool check(string str1, string str2)
{
    if(str1.length() != str2.length())
        return false;
    
    string concat = str1+str1;
    
    for(int i=0;i<concat.length();i++)
    {
        string sub = concat.substr(i,str2.length());
        if(sub==str2)
            return true;
    }
    return false;
}

int main()
{
    string str1 = "ABCD";
    string str2 = "CABD";

    cout<<"Check if valid rotation is valid :- "<<(check(str1,str2) ? "Yes" : "No")<<endl;

}