// Given nos 1-n find the no. of different bst's possible
#include<iostream>
using namespace std;

// Brute Force TC : O(N^2)
int bst(int N)
{
    if(N<0)
        return 0;

    if(N==1 || N==0)
        return 1;
        
    int total=0;

    for(int i=0;i<N;i++)
    {
        total+=bst(i) * bst(N-i-1);
    }
    return total;
}

int main()
{
    int N = 4;
    cout<<"Total BST's possible :- "<<bst(N)<<endl;
}