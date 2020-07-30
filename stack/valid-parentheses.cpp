// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkValid(string str)
{
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            st.push(str[i]);
        else
        {
            if(st.size()!=0)
            {
                char ch = st.top();
                if((ch=='[' && str[i]!=']') || (ch=='{' && str[i]!='}') || (ch=='(' && str[i]!=')'))
                    return false;
                else
                    st.pop();
            }
            else
                return false;
            
        }
    }
    if(st.size()==0)
        return true;
    else
        return false;
}

int main()
{
    string str="(([]))";
    cout<<"Is the sequence valid : "<<(checkValid(str)?"Yes":"No")<<endl;
}