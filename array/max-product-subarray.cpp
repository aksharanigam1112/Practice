#include<iostream>
using namespace std;

// Brute Force TC : O(N^2)

// TC : O(N) 
int maxProduct(int arr[],int size)
{
    int min_prd = arr[0];
    int max_prd = arr[0];
    int Max = arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]<0)
            swap(min_prd , max_prd);
        
        min_prd = min(arr[i], arr[i]*min_prd);
        max_prd = max(arr[i], arr[i]*max_prd);
        Max = max(max_prd,Max);
    }
    return Max;
}

int main()
{
    int arr[] = {1,-1,0,2,-1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max product subarray :- "<<maxProduct(arr,size)<<endl;
}