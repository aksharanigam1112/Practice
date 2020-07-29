// Given a palindromic number having n number of digits. 
// Find the next larger palindromic number greater than the given using the same set of digits 
// C++ implementation to find next higher 
// palindromic number using the same set 
// of digits 
#include<iostream>
#include<string> 
using namespace std; 

// function to reverse the digits in the 
// range i to j in 'arr' 
void reverse(string arr, int i, int j) 
{ 
	while (i < j) { 
		swap(arr[i], arr[j]); 
		i++; 
		j--; 
	} 
} 

// function to find next higher palindromic 
// number using the same set of digits 
string nextPalin(string arr) 
{ 
    int n = arr.length();
	if(n<=3) 
        return "-1";

	int mid = (n/2) - 1, i; 

	// find the first digit that is smaller than the digit next to it. 
	for(i = mid-1; i>=0; i--)
    { 
		if (arr[i] < arr[i + 1]) 
			break; 
    }

	// If no such digit is found, then all 
	// digits are in descending order which 
	if(i<0) 
        return "-1";

	// Find the smallest digit on right of ith digit which is greater 
	// than arr[i] up to index 'mid' 
	int smallest = i + 1; 
	for(int j=smallest+1; j<=mid; j++)
    { 
		if (arr[j] > arr[i] && arr[j] < arr[smallest]) 
			smallest = j; 
    }

	// swap on both left & right parts
	swap(arr[i], arr[smallest]); 

	swap(arr[n - i - 1], arr[n - smallest - 1]); 

	// reverse digits in the range (i+1) to mid 
	reverse(arr, i + 1, mid); 

	if (n % 2 == 0) 
		reverse(arr, mid + 1, n - i - 2); 

	else
		reverse(arr, mid + 2, n - i - 2); 

	return arr; 
} 

// Driver program to test above 
int main() 
{ 
	string arr = "4697557964"; 
    string ans = nextPalin(arr);
	cout<<"Next larger palindromic no : "<<(ans!="-1" ? ans :"Not Possible")<<endl; 
} 
