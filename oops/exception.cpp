#include<iostream>
#include<vector>
using namespace std;

void sumDivide(vector<int>&arr)
{
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        if((i+1)%2==0)
            sum+=arr[i];
    }
    arr.push_back(sum);
    throw -1;
}

int main()
{
    vector<int>arr;

    cout<<"Enter array elements : ";
    for(int i=0;i<5;i++)
    {
        int n ; 
        cin>>n;
        arr.push_back(n);
    }

    try
    {
        sumDivide(arr);
    }
    catch(int x)
    {
        cout<<"Arithmetic Exception Caught (Division by Zero)"<<endl;
    }

    cout<<"New Array : ";
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}