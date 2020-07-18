#include<iostream>
#include <bits/stdc++.h> 
#include<string>
using namespace std; 

// Inplace Permutations

void permute(string a, int l, int r) 
{  
	if (l == r) 
		cout<<a<<endl; 
	else
	{ 
		for (int i = l; i <= r; i++) 
		{ 
			swap(a[l], a[i]); 
			permute(a, l+1, r); 
			swap(a[l], a[i]); 
		} 
	} 
} 

void print(string str)
{
    for(int i=0;i<str.length();i++)
    {
        cout<<str[i];
    }
    cout<<endl;
}

// Creating Different String 

void permuatations(string selection , string rem)
{
    if(rem.length() == 0 )
    {
        print(selection);
        return ;
    }

    for(int i=0;i<rem.length();i++)
    {
        char s = char(rem[i]);
        string remcopy = rem.substr(0,i) + rem.substr(i+1);
        selection.push_back(s);
        permuatations(selection,remcopy);
        selection.pop_back();
    }
}

int main() 
{ 
	string str = "ABC"; 
	int n = str.size(); 
	cout<<"\nThrough inplace:- \n";
    permute(str, 0, n-1); 

    cout<<"\nBy creating different string:- \n";
    permuatations("",str);
	return 0; 


} 
