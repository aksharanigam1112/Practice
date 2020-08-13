// Implement next permutation, which rearranges numbers into 
// the lexicographically next greater permutation of numbers.
// Ex : 1,2,3 ===> 1,3,2
// If such arrangement is not possible, it must rearrange it as the lowest possible order
#include<iostream>
#include<algorithm>
using namespace std;

// TC : O(N)    &   SC : O(1)
void permute(int arr[], int size)
{
    int pos=-1,diff=9999,k;
    for(int i=size-1;i>0;i--)
    {
        if(arr[i-1] < arr[i])
        {
            pos = i-1;
            break;
        }
    }
    if(pos==-1)
        reverse(arr,arr+size);
    else
    {
        k = pos+1;
        for(int j=pos+1;j<size;j++)
        {
            if(arr[j] > arr[pos] && arr[j] < arr[k])
                k = j;
        }

        swap(arr[pos],arr[k]);
        reverse(arr+pos+1,arr+size);
    }
}

int main()
{
    int arr[] = {2,1,8,7,6,5};

    int size = sizeof(arr)/sizeof(arr[0]);
    permute(arr,size);
    cout<<"Next greater permutation is : ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<", ";
    cout<<endl;
}