#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len1= 9, len2 = 4,r2=len2-1,r1=len1-len2-1,w=len1-1;
    int arr1[len1]= {8,15,21,45,60};
    int arr2[len2] = {5,12,15,24};
    while(r1>=0 && r2>=0)
    {
        if(arr1[r1]>arr2[r2])
        {
            arr1[w--] = arr1[r1--];
        }
        else if(arr1[r1]<arr2[r2])
        {
            arr1[w--] = arr2[r2--];
        }
        else //if(arr1[r1]==arr2[r2])
        {
            arr1[w--] = arr1[r1--];
            arr1[w--] = arr2[r2--];
        }
    }
    while(r2>=0)
    {
        arr1[w--] = arr2[r2--]; 
    }
    while(r1>=0)
    {
        arr1[w--] = arr1[r1--];
    }
    
    for(int i=w+1;i<len1;i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;
}