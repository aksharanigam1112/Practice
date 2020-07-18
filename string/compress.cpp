// Compress string with continuous count if possible ( aabbbcdeeaaa => a2b3c1d1e2a3 )
#include<iostream>
#include<string>
using namespace std;

string compress(string str)
{
    str.append(" ");
    string comp="";
    char prev = str[0];
    int count = 1;
    
    for(int i=1;i<str.length();i++)
    {
        if(str[i]==prev)
            count++;

        if(str[i]!=prev)
        {
            comp += prev+to_string(count);
            count=1;
            prev = str[i];
        }
    }
    return comp;
}

int main()
{
    string str = "aabbbcdeeaaa";
    cout<<"Compressed String : "<<compress(str)<<endl;
}