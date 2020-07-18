#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void printSubset(int sel[] , string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(sel[i]==1)
            cout<<str[i];
    }
    cout<<endl;
}

// Brute force O(2^N)

void allSubsets1(string str , int size , int index , int sel[])
{
    if(index>=size)
    {
        printSubset(sel , str);
    }
    else
    {
        //select element in subset
        sel[index] = 1;
        allSubsets1(str , size , index+1 , sel);

        //selection not made
        sel[index]=0;
        allSubsets1(str,size,index+1,sel);
    }
}

// copy & combine

// list <char> allSubsets2(string str , int size , int index)
// {
//     list<char>result;
//     if(index>=size)
//     {
//         result.push_back(' ');
//         return result;
//     }
//     list<char>l = allSubsets2(str,size,index+1);
//     list<char>copied = copyList(l);
//     copied = addCurrentElement(copied , str[index]);
//     result = combined(l,copied);
//     return result;
// }

// skipping the selected

void print(list<char>sel)
{
    list<char>::iterator it = sel.begin();
    while(it!=sel.end())
    {
        cout<<*it;
        it++;
    }
    cout<<endl;
}

void allSubsets3(string str , int size , int index , list<char>sel)
{
    if(index>=size)
    {
        print(sel);
        return;
    }
    for(int i=index;i<size;i++)
    {
        sel.push_back(str[i]);
        allSubsets3(str,size,i+1,sel);
        sel.pop_back();
    }
    print(sel);
}

int main()
{
    string str = "ABC";
    int sel[str.length()];
    memset(sel,-1,str.length());
    cout<<"Brute force\n";
    allSubsets1(str,str.length() , 0,sel);
    list<char>select;
    cout<<"Optimized \n";
    allSubsets3(str,str.length(),0,select);
}