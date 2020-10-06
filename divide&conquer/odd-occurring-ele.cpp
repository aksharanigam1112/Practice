// Given an array of integers where each element occurs even no. of times except one.
// Find that odd occuring element in O(log N) time.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findOddOccuring(int arr[], int low, int high)
{
	if (low == high)
		return low;

	int mid = (low + high) / 2;

	if(mid%2 !=0)
	{
		// if element before mid is same as mid element, the odd element
		// lies on the right side; otherwise it lies on the left side
		if (arr[mid] == arr[mid - 1])
			return findOddOccuring(arr, mid + 1, high);
		else
			return findOddOccuring(arr, low, mid - 1);
	}

	else
	{
		// if element next to mid is same as mid element, the odd element
		// lies on the right side; otherwise it lies on the left side
		if (arr[mid] == arr[mid + 1])
			return findOddOccuring(arr, mid + 2, high);
		else
			return findOddOccuring(arr, low, mid);
    }
}

int main()
{
    int arr[] = { 2, 2, 1, 1, 3, 3, 2, 2, 4, 4, 3, 1, 1 };
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Odd occuring element is : "<<arr[findOddOccuring(arr,0,size-1)]<<endl;
}