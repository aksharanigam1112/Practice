#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Sorting & then doing a linear search from 1 - n+1 TC :- O(nlog n + n)

// Hashing (Mark Present) & the linear search TC :- O(n) & SC :- O(n)

//Segregating +ve & -ve values & then linear search for the +ve values TC: O(n) & SC :- 0(1)

void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int searchMinPos(int*arr, int size)
{
    for(int i = 0; i < size; i++) 
    { 
        if( abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
        
        print(arr,size);
    } 
  
    for(int i = 0; i < size; i++) 
    {
        if (arr[i] > 0) 
            return i + 1; 
    }
    
    return size + 1; 
}


int segregate(int *arr , int n)
{
    int neg=0;
    for(int pos=0;pos<n;pos++)
    {
        if(arr[pos]<=0)
        {
            swap(arr[pos],arr[neg]);
            neg++;
        }
    }

    return searchMinPos(arr+neg,n-neg);
}



int main()
{
    int arr[] = {2,3,-7,6,8,1,-10,15,4,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"First missing positive value : "<<segregate((int *)arr,n)<<endl;
    
}