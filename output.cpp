#include<iostream>
using namespace std;

int fun(int a, int b=10)
{
    return(a = a*b+2);
}

int main()
{
    cout<<fun(1)<<endl;
    cout<<fun(3,4)<<endl;
}