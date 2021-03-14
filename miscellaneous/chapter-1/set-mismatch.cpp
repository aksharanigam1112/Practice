// You are given an integer array, Find the number that occurs twice and 
// the number that is missing and return them.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void setMismatch(int arr[], int n){

    int repeatedNum = 0 ;
    int missingNum = arr[0];
    
    int sum = n*(n+1)/2;
    sum -=missingNum;

    arr[missingNum-1] =- arr[missingNum-1];

    for(int i=1;i<n;i++){
        if(arr[abs(arr[i])-1]<0)
            repeatedNum = abs(arr[i]);
    
        else
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    
        sum -=abs(arr[i]);
    }
    cout<<repeatedNum<<" "<<repeatedNum+sum<<endl;
  
}

int main(){
    int arr[] = {1,2,3,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Repeating & Missing no. is : ";
    setMismatch(arr,n);
}