// Find the number which is next greater than the given
#include <iostream> 
#include <cstring>
#include<bits/stdc++.h>  
using namespace std; 

// TC : O(N+ NlogN)

void findNext(char number[], int n) 
{ 
	int i, j; 

	for(i = n-1; i > 0; i--) 
	{
        if (number[i] > number[i-1]) 
		    break;
    } 

	if (i==0) 
	{ 
		cout<<"Next number is not possible"<<endl; 
		return; 
	} 

	int x = number[i-1], smallest = i; 
	for(j = i+1; j < n; j++)        // Can use Binary Search instead of Linear Search
	{
        if (number[j] > x && number[j] < number[smallest]) 
			smallest = j; 
    }

	swap(number[smallest], number[i-1]); 
	sort(number + i, number + n); 

	cout<<"Next number with same set of digits is : "<<number<<endl; 

	return; 
} 

int main() 
{ 
	char digits[] = "534976"; 
	int n = strlen(digits); 
	findNext(digits, n); 
	return 0; 
} 
