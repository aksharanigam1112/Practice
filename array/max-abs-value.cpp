// You are given an array of N integers. 
//Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
#include<iostream>
using namespace std;

int absolute(int arr[], int size)
{
    int maxVal=0, start=0;
    for(int i=1;i<size;i++)
    {
        int val1 = abs(arr[i]-arr[i-1]) + 1;
        int val2 = abs(arr[i]-arr[start]) + abs(i-start);
        if(val1>val2)
            start = i;
        cout<<arr[i]<<" "<<val1<<" "<<val2<<endl;
        maxVal = max(val1,max(maxVal,val2)); 
    }
    return maxVal;
}

int main()
{
    int arr[] = { -70, -64, -6, -56, 64, 61, -57, 16, 48, -98 };
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max Absolute value : "<<absolute(arr,size)<<endl;
}