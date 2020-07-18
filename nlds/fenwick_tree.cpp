#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getParent(int pos) 
{
    int temp = pos & (-pos);
    return (pos-temp);
}

int getNext(int pos) 
{
    int temp = pos & (-pos); 
    return (pos+temp);
}

void update(int fenwickTree[], int size, int pos, int val) 
{
    pos++;
    while(pos <= size) 
    {
        fenwickTree[pos] += val;
        pos += pos & (-pos);
    }
}

int getSum(int fenwickTree[], int pos) 
{
    int sum = 0;
    pos++;
    while(pos > 0) 
    {
        sum += fenwickTree[pos];
        pos -= pos & (-pos);
    }
    return sum;
}

int* createFenwickTree(int arr[], int size) 
{
    int *fenwickTree = new int[size + 1];
    memset(fenwickTree,0,sizeof(fenwickTree));

    for(int i = 0; i < size; i++) 
    {
        update(fenwickTree, size, i, arr[i]);
    }
    return fenwickTree;
}


int main() 
{
    int size, x;
    cout<<"\nEnter the no. of elements:- ";
    cin>>size;

    int arr[size];
    cout<<"\nEnter the values :- ";
    
    for(int i = 0; i < size; i++) 
    {
        cin>>arr[i];
    }

    int *fenwickTree = createFenwickTree(arr, size);
    
    cout<<"\nEnter the position to find sum :- ";
    cin>>x;
    cout<<getSum(fenwickTree, x-1)<<endl;

    cout<<"\nEnter the position to find the parent & next of :- ";
    cin>>x;
    cout<<fenwickTree[getParent(x)]<<" "<<fenwickTree[getNext(x)]<<endl;
    return 0;
}

