// Partition array into k disjoint subsets such that sum of each partition is equal
// without repeatition
#include <iostream>
#include <numeric>
using namespace std;

bool checkSum(int sumLeft[], int k)
{
	for(int i=0; i<k; i++)
	{
		if (sumLeft[i] != 0)
			return false;
	}
	return true;
}

bool subsetSum(int arr[], int n, int sumLeft[], int A[], int k)
{
	if (checkSum(sumLeft, k))
		return true;

	if (n < 0)
		return false;

	bool res = false;

	for(int i=0; i<k; i++)
	{
		if(!res && sumLeft[i]-arr[n] >= 0)
		{
			A[n] = i + 1;
            sumLeft[i] -= arr[n];
			res = subsetSum(arr, n-1, sumLeft, A, k);
			sumLeft[i] += arr[n];
		}
	}
	return res;
}

void partition(int arr[], int n, int k)
{
	if (n<k)
	{
		cout<<"Not Possible"<<endl;
		return;
	}

	int sum = accumulate(arr, arr+n, 0);

 	int A[n], sumLeft[k];

 	for(int i=0; i<k; i++)
		sumLeft[i] = sum/k;

	if (sum%k==0 && subsetSum(arr,n-1,sumLeft,A,k)==false)
	{
		cout<<"Not Possible";
		return;
	}

    for(int i=0; i<k; i++)
	{
		cout<<"Partition "<<i+1<<" is : ";
	   	for (int j=0; j<n; j++)
        {
	 		if (A[j] == i+1)
	 			cout<<arr[j]<<" ";
        }
        cout<<endl;
	}
}

int main()
{
	int arr[] = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 5;
	partition(arr,size,k);
}