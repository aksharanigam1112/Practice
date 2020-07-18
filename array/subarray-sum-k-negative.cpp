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

		if (curr_sum==k) 
		{ 
			cout <<"Sum found between indexes "<<0<<" to "<<i<< endl; 
			return; 
		} 

		if (m.find(curr_sum-k)!=m.end()) 
		{ 
			cout<<"Sum found between indexes "<<m[curr_sum-k]+1<<" to "<<i<< endl; 
			return; 
		} 

		m[curr_sum] = i; 
    }
    cout<<"Sum not found "<<endl;
}

int main()
{
    int arr[] = {1,4,45,6,0,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 60;
    sumK(arr,n,k);
}