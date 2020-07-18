// Given an array with n objects of 0's 1's and 2's, 
// sort them in-place so that objects of the same type are adjacent/together 
// The functions should put all 0s first, then all 1s and all 2s in last.
#include<iostream>
#include<algorithm>
using namespace std;

void sort(int arr[], int size)
{
    int low=0, mid=0, high = size-1;

    for(int i=0;i<size && mid<=high ;)
    {
        if(arr[i]==0)
        {
            swap(arr[i],arr[low]);
            low++;
            mid++;
            i++;
        }
        else if(arr[i]==1)
        {
            mid++;
            i++;
        }
        else if(arr[i]==2)
        {
            swap(arr[i],arr[high]);
            high--;
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={2,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Sorted array : ";
    sort(arr,size);
}
