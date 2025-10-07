#include<iostream> 
#include<deque>
using namespace std; 

void printKMax(int arr[], int n, int k) 
{ 
	deque<int> window(k); 

	for(int i=0; i<k; i++) 
    { 
		while ((!window.empty()) && arr[i] >= arr[window.back()]) 
			window.pop_back(); 

		window.push_back(i); 
	} 

	for(int i=k;i<n;i++) 
    { 
		cout << arr[window.front()] << " "; 

		// Remove the elements which are out of this window 
		while ((!window.empty()) && window.front() <= i - k) 
			window.pop_front();  

		while ((!window.empty()) && arr[i] >= arr[window.back()]) 
			window.pop_back(); 

		window.push_back(i); 
	} 

	cout<<arr[window.front()]<<endl; 
} 

int main() 
{ 
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	printKMax(arr, n, k); 
	return 0; 
}
