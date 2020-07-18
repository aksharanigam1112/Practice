#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(char*sel)
{
    for(int i=0;i<4;i++)
        cout<<sel[i]<<" ";
    cout<<endl;
}

void allMnemonics(int*arr,char*sel,int size,int pos,map<int,list<char>>hash)
{
    if(pos==size)
    {
        print(sel);
        return;
    }
    list<char> values = hash.find(arr[pos])->second;
    for(list<char>::iterator it = values.begin();it!=values.end();it++)
    {
        sel[pos] = *it;
        allMnemonics(arr,sel,size,pos+1,hash);
    }

}

int main()
{
    map<int,list<char>>hash;
    
    list<char> l;
    l.push_back('a');
    l.push_back('b');
    l.push_back('c');

    hash.insert(make_pair(1,l));
    l.clear();

    l.push_back('c');
    l.push_back('d');
    l.push_back('e');

    hash.insert(make_pair(2,l));
    l.clear();

    l.push_back('f');
    l.push_back('g');
    l.push_back('h');
    l.push_back('i');

    hash.insert(make_pair(3,l));
    l.clear();

    l.push_back('j');
    l.push_back('k');
    l.push_back('l');

    hash.insert(make_pair(4,l));
    l.clear();

    l.push_back('m');
    l.push_back('n');
    l.push_back('o');

    hash.insert(make_pair(5,l));
    l.clear();

    l.push_back('p');
    l.push_back('q');
    l.push_back('r');

    hash.insert(make_pair(6,l));
    l.clear();

    l.push_back('s');
    l.push_back('t');
    l.push_back('u');

    hash.insert(make_pair(7,l));
    l.clear();

    l.push_back('v');
    l.push_back('w');
    l.push_back('x');

    hash.insert(make_pair(8,l));
    l.clear();

    l.push_back('y');
    l.push_back('z');

    hash.insert(make_pair(9,l));
    l.clear();

    int arr[]= {2,4,6,8};
    char sel[4];
    allMnemonics(arr,sel,4,0,hash);
}