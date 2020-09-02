// Equilibrium index of an array is an index such that the sum of elements at lower indexes 
// is equal to the sum of elements at higher indexes
#include<iostream>
using namespace std;

int findEq(int arr[], int size)
{
    int sum=0,leftSum=0;

    for (int i=0; i<size; i++)  
        sum += arr[i];  
  
    for (int i=0; i<size; i++)  
    {  
        leftSum+=arr[i];

        if(leftSum==sum)
            return i;
        sum-=arr[i];
    }
    return -1;  
}

int main()
{
    int arr[] = {-7,1,5,2,-4,3,0};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Equilibrium index : "<<findEq(arr,size)<<endl;
}