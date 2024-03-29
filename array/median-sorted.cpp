// Find median of two sorted arrays
#include<iostream>
using namespace std;

// Optimized TC: O(min(LogN,LogM))  SC : O(1)


// TC : O(N) SC : O(1)

float findMedian1(int a[], int n1, int b[], int n2) 
{ 
	int i = 0,j = 0,m1 = -1, m2 = -1;

	for(int k=0; k<=(n1 + n2)/2; k++) 
    { 
		if (i < n1 && j < n2) 
        { 
			if (a[i] < b[j]) 
            { 
				m2 = m1; 
				m1 = a[i]; 
				i++; 
			} 
			else 
            { 
				m2 = m1; 
				m1 = b[j]; 
				j++; 
			} 
		} 

		else if (i == n1) 
        { 
			m2 = m1; 
			m1 = b[j]; 
			j++; 
		} 
        else if (j == n2) 
        { 
			m2 = m1; 
			m1 = a[i]; 
			i++; 
		} 
	} 

	if ((n1 + n2) % 2 == 0) 
		return (m1 + m2)*1.0/2; 

	return m1; 
} 

int main() 
{ 
	int a[] = {1, 2,};
    int b[] = {3,4};  
	int n1 = sizeof(a) / sizeof(a[0]); 
	int n2 = sizeof(b) / sizeof(b[0]); 

	cout<<"Median is : "<<findMedian1(a, n1, b, n2)<<endl;
} 
