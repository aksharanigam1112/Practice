// Evaluate reverse polish notation (postfix) and return the ans
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int postfix(string arr[], int size)
{
    stack<int>s;
    for(int i=0;i<size;i++)
    {
        if(arr[i]=="+" || arr[i]=="-" || arr[i]=="*" || arr[i]=="/")
        {
            int sec = s.top();
            s.pop();
            int fir = s.top();
            s.pop();
            
            if(arr[i]=="+")
                s.push(fir+sec);
            else if(arr[i]=="-")
                s.push(fir-sec);
            else if(arr[i]=="*")
                s.push(fir*sec);
            else
                s.push(fir/sec);            
        }
        else
            s.push(stoi(arr[i]));
    }
    return s.top();
}

int main()
{
    string arr[]=  {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Evaluated expression is : "<<postfix(arr,size)<<endl;
}