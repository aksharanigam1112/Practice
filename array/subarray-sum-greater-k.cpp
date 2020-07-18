#include<iostream>
#include<map>
using namespace std;

void sumK(int arr[], int n, int k)
{
    map<int,int>m;

    int curr_sum=0;

    for(int i=0;i<n;i++)
    {
        curr_sum = curr_sum + arr[i]; 

		if(curr_sum==k) 
		{ 
			cout<<"Min Length of Subarray : "<<(i+1)<<" with sum : "<<curr_sum+arr[i+1]<<endl; 
			return; 
		} 

		if(m.find(curr_sum-k)!=m.end() ) 
		{ 
			cout<<"Min Length of subarray : "<<abs(m[curr_sum-k]-(i+1))<<" with sum : "<<curr_sum<<endl; 
			return; 
		} 

        if(arr[i]>k)
        {
            cout<<"Min Length of Subarray : 1"<<" with sum : "<<arr[i]<<endl;
            return;
        }

		m[curr_sum] = i; 
    }
    cout<<"Min Length, sum not found "<<n+1<<endl;
}

int main()
{
    int arr[] = {1,4,45,6,0,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 51;
    sumK(arr,n,k);
}