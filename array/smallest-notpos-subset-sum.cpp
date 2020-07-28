// Given a sorted array of positive numbers, 
// find the smallest positive integer value that cannot be 
// represented as sum of elements of any subset of given set. 
#include<iostream>
using namespace std;

// TC : O(N)
int findSmallest(int arr[], int n) 
{ 
   int res = 1; 
  
    for(int i = 0; i<n; i++)
    {
        if(arr[i]>res)
            break;
        else 
            res = res + arr[i]; 
    }
   return res; 
} 
int main()
{
    int arr[] = {1, 2, 6, 10, 11, 15};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Smallest that can't be represented as subset sum is : "<<findSmallest(arr,size)<<endl;
}