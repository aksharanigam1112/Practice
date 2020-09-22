// Remove duplicate characters in a given string keeping only the first occurrences. 
// For example, if the I/P : ‘tree traversal’ ==>  O/P : ‘tre avsl’.
#include<iostream>
#include<string>
#include<set>
using namespace std;

string removeDuplicates(string str)
{
    set<char>hash;
    for(int i=0;i<str.length();i++)
        if(hash.find(str[i])==hash.end())
            hash.insert(str[i]);
        
    string ans = "";
    for(int i=0;i<str.length();i++)
    {
        if(hash.find(str[i]) != hash.end())
        {
            ans+=str[i];
            hash.erase(str[i]);
        }
    }
    return ans;
}

int main()
{
    string str = "geeks for geeks";
    cout<<"After removing duplicates : "<<removeDuplicates(str)<<endl;
}