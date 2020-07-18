#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force O(n^2)

// left prod & right prod TC :- O(n) SC :- O(n)
int findMax(int*prd,int size)
{
    int pos=0,max=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(prd[i]>max)
        {
            max = prd[i];
            pos = i;
        }
    }
    return pos;
}

void maxProduct(int arr[] , int size)
{
    int left[size] , right[size] , prd[size];
    left[0] = 1;
    right[size-1] = 1;
    for(int i=1;i<size;i++)
    {
        left[i] = left[i-1] * arr[i-1];
    }
    for(int i=size-2;i>=0;i--)
    {
        right[i] = right[i+1]*arr[i+1];
    }

    for(int i=0;i<size;i++)
    {
        prd[i] = left[i] * right[i];
    }

    int pos = findMax(prd,size);
    cout<<"Max product is : "<<prd[pos]<<" except element : "<<arr[pos]<<endl;
}

int main()
{
    int arr[] = {-1,5,3,0,4,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    maxProduct(arr,n);
}