#include <iostream> 
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
	if(i>n)
        return;

    // int largest = i;
	int l = 2*i + 1;  
	int r = 2*i + 2; 

    if(l>=n)
        return;
    
    int minEle = r>=n ? l:(arr[r]<arr[l]?l:r);

    if(arr[minEle]>arr[i])
    {
        swap(arr[minEle],arr[i]);
        heapify(arr,n,minEle);
    }

    
    cout<<"After heapify : ";
    for (int j=0; j<n; ++j) 
		cout << arr[j] << " "; 
	cout<<endl;  
} 

void heapSort(int arr[], int n) 
{ 
	for (int i = n / 2 ; i >= 0; i--) 
		heapify(arr, n, i); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]); 
		heapify(arr, i, 0); 
	} 
    for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout<<endl; 
} 



int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n); 

	
	// printArray(arr, n); 
} 
