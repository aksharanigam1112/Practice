// Given an array of integers, find a subset in it
// that has maximum product & return it
#include<iostream>
#include<climits>
using namespace std;

int maxProductSubset(int arr[], int size)
{
    if(size==0)
        return 0;
    if(size==1)
        return arr[0];
    
    int min_neg=INT_MAX, neg=0,pos=0,prd=1;
    bool hasZero = false;

    for(int i=0;i<size;i++)
    {
        if(arr[i]<0)
        {
            neg++;
            min_neg = min(min_neg,-arr[i]);
        }
        if(arr[i]>0)
            pos++;
        
        if(arr[i]==0)
            hasZero = true;
        else
            prd = prd*arr[i];
    }

    if(neg%2!=0)
        prd = prd/-min_neg;
    if(neg==1 && hasZero && pos==0)
        prd=0;

    return prd;
}

int main()
{
    int arr[] = {4,-8,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Maximum product is : "<<maxProductSubset(arr,n)<<endl;
}