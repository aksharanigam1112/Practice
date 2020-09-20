// Alterrnate peak valley arrangement  of the array
// Even Pos : Greater Element
// Odd Pos : Smaller Element
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Sort & swap alternate elements  TC : O(N LogN)

// TC : O(N)
void peakValley(int arr[], int size)
{
    for(int i=1;i<size;i+=2)
    {
        if(arr[i-1] > arr[i])
            swap(arr[i],arr[i-1]);
        
        if(i+1<size && arr[i+1] > arr[i])
            swap(arr[i],arr[i+1]);
    }

    // Printing the array
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}

int main()
{
    int arr[] = {6,9,2,5,4,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Peak Valley array : ";
    peakValley(arr,size);
}