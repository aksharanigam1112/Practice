// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
#include<iostream>
#include<string>
using namespace std;

// This problem is a variation of Matrix Chain Multiplication problem. 
// If the string is a palindrome, then we simply return 0. 
// Else, we try making cuts at all possible places,recursively 
// calculate the cost for each cut and return the minimum value. 

int partition(string str)
{
    
}

int main()
{
    string str = "aab";
    cout<<"All possible palindrome partitioning are : "<<endl;
    partition(str);
}