// Rotate a string by ith index.
#include<iostream>
#include<string>
using namespace std;

string leftRotate(string str, int d)
{
    string s1 = str.substr(0,d);
    string s2 = str.substr(d);
    return s2+s1;
}

string rightRotate(string str, int d)
{
    string s1 = str.substr(0,str.length()-d);
    string s2 = str.substr(str.length()-d);
    return s2+s1;
}

int main()
{
    string str = "QWERTYU";
    int d=2;
    cout<<"Left Rotation : "<<leftRotate(str,d)<<endl;
    cout<<"Right Rotation : "<<rightRotate(str,d)<<endl;
    
}