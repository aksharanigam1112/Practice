#include<iostream>
using namespace std;

// TC :- O(n) 

void increasingSubarray(int *arr , int n)
{
    int len=1,max=1;
    cout<<arr[0]<<" ";

    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            cout<<arr[i]<<" ";
            len++;
        }
        else
        {
            if(len>max)
                max = len;
            cout<<"= "<<len<<endl<<arr[i]<<" ";
            len=1;
        }
    }
    cout<<"= "<<len<<endl;
    cout<<"Size of Longest Subarray : "<<max<<endl;
}
int main() 
{ 
    int arr[] = {5, 6, 3, 5, 7, 8, 9, 1, 2}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    increasingSubarray(arr, n); 
    return 0;      
} 