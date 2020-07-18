#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "abcdabxyzab";

    cout<<"Positon of first occurance of 'ab' : "<<str.find_first_of("ab")<<endl;
    cout<<"Positon of last occurance of 'ab' : "<<str.find_last_of("ab")<<endl;

    cout<<"Position of first occurance of 'mno' : "<<(str.find_first_of("mno")!=string::npos ? "Found" : "Not Found")<<endl;
    
}