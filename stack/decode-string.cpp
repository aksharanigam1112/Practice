// Given an encoded string, return its decoded string.
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string decode(string str)
{
    string res;
    
    stack<int> num;
    stack<string> dict;
        
    int count = 0;
    for(int i=0; i<str.length(); i++)
    {
        if((str[i]>='a' && str[i] <= 'z') || (str[i]>='A' && str[i] <= 'Z'))
        {
            if(num.empty()) 
                res+= str[i];
            else 
                dict.top()+= str[i];
        }
        else if(str[i]>='0' && str[i] <= '9') 
        {
                    count*=10;
                    count+=str[i]-'0';
                    // count the number
        }
        else if(str[i]=='[')
        {
            num.push(count);
            count = 0;
            dict.push("");
        }
        else if(str[i]==']')
        {
            string x;
            for(int i=0;i<num.top();i++) 
                x+= dict.top();
            
            dict.pop();
            num.pop();
                    
            if(!dict.empty())
                dict.top()+=x;
            else 
                res+=x;
        }
    }
    return res;
}

int main()
{
    string str="a3[bc2[de]]";
    cout<<"Decoded string is : "<<decode(str)<<endl;
}