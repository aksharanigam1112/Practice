// Minimize the search cost of the BST
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int searchCostBST(int ele[], int freq[], int size)
{
    
}

int main()
{
    int ele[] = {1,5,8,15,20,25,40};
    int freq[] = {100,5,25,5,10,15,10};
    int size = sizeof(ele)/sizeof(ele[0]);

    cout<<"Minimum search cost : "<<searchCostBST(ele,freq,size)<<endl;
}