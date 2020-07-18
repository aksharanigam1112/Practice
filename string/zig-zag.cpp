// Given a string and number of rows ‘n’. Print the string formed by concatenating n rows 
// when input string is written in row-wise Zig-Zag fashion.
#include<iostream>
#include<string>
using namespace std;

// Brute Force TC : O(N^2)


// TC : O(N) SC : O(N)
string zigZag(string str, int n)
{
    string arr[n];
    int row = n-1;
    char dir;
    for(int i=0;i<str.length();i++)
    {
        arr[row].push_back(str[i]);
        if(row==n-1)   
            dir = 'D';
        else if (row==0)
            dir = 'U';
        
        if(dir == 'D')
            row--;
        else if(dir=='U')
            row++;
    }

    string final="";
    for(int i=n-1;i>=0;i--)
    {
        final = final+" "+arr[i];
    }
    return final;
}

int main()
{
    string str="GEEKSFORGEEKS";
    int n=4;
    cout<<"Zig Zag string : "<<zigZag(str,n)<<endl;
}