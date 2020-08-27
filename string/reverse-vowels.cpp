// Reverse only the vowels of a string
#include<iostream>
#include<string>
using namespace std;

string reverse(string str)
{
    int first=-1, last=-1,n=str.length();
    string vow = "AEIOUaeiou";

    
    for(int i=0;i<n && first<=last;i++)
    {
        if(vow.find(str[i]) != string::npos)
            first = i;
        if(vow.find(str[n-i-1]) != string::npos)
            last = n-i-1;

        cout<<"i : "<<i<<endl;
        if(first != -1 && last != -1 && first<=last)
        {
            cout<<"first : "<<first<<" last : "<<last<<endl;
            swap(str[first],str[last]);
            cout<<"\tstr : "<<str<<endl;
            first = last = -1;
        }
    }
    return str;
}

int main()
{
    string str = "RACE A CAR";
    cout<<"Reverse Vowels : "<<reverse(str)<<endl;
}