#include<iostream>
#include<list>
#include<string>
using namespace std;

void print(list<char>sel)
{
    list<char>::iterator it;
    for(it=sel.begin();it!=sel.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;
}

void kSubset(string str, int size , int index , int k , list<char>sel)
{
    if(sel.size()==k)
    {
        print(sel);
        return;
    }
    if(index>=size)
        return;

    for(int i=index;i<size;i++)
    {
        sel.push_back(str[i]);
        kSubset(str,size,i+1,k,sel);
        sel.pop_back();
    }
}

int main()
{
    string str = "ABC";
    list<char>sel;
    int k=3;
    kSubset(str,str.length(),0,k,sel);
}