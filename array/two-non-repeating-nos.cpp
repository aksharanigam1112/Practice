//  Find 2 values in array which are not repeated. 
// Array has 2N+2 values with N+2 unique values. Except 2 all other numbers are repeated.
#include<iostream>
using namespace std;

void repeat(int arr[], int size)
{
    int res = arr[0];
    for(int i=1;i<size;i++)
        res = res ^ arr[i];

    // Find 2's comp OR the right most set bit which tell the least bit difference between 
    // two non-repeating nos
    int res_comp = res & ~(res-1);

    // cout<<"XOR no : "<<res<<endl;
    // cout<<"2's compliment : "<<res_comp<<endl;

    int x = 0;
    for(int i=0;i<size;i++)
    {
        if((arr[i] & res_comp)>0)
        {
            // cout<<arr[i]<<" , "<<(arr[i]&res_comp)<<endl;
            x = x ^ arr[i];
        }
    }
    cout<<x<<" , "<<(res^x)<<endl; 
}

int main()
{
    int arr[] = {2,3,7,9,11,2,3,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Two non repeating nos are : ";
    repeat(arr,size);
}