#include<iostream>
using namespace std;

void sumK(int arr[], int size, int k)
{
    int curr_sum=0, start = 0; 
  
    for (int i=0;i<=size;i++) 
    { 
        curr_sum = curr_sum + arr[i]; 

        while (curr_sum > k && start<i) 
        { 
            curr_sum = curr_sum-arr[start]; 
            start++; 
        } 
  
        if (curr_sum == k) 
        { 
            cout<<"Sum found between : "<<start<< " and "<<i<<endl; 
            return ; 
        } 
    } 
  
    cout<<"Not found "<<endl; 
}

int main()
{
    int arr[] = {2,4,45,6,0,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    sumK(arr,n,k);
}