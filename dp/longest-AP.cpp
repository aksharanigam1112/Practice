// Given a set of numbers, 
// find the Length of the Longest AP (LLAP) in it. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force :- TC : O(N^3)

// DP :- TC : O(N^2)     &      SC : O(N^2)
int longestAP(int arr[], int n) 
{ 
	if (n <= 2) 
        return n; 

	int L[n][n]; 
	int llap = 2;  

    // Last col
	for(int i=0; i<n; i++) 
		L[i][n-1] = 2; 

	for(int j=n-2; j>=1; j--) 
	{ 
		int i = j-1, k = j+1; 
		while(i>=0 && k<n) 
		{ 
		    if (arr[i] + arr[k] < 2*arr[j]) 
			    k++; 
		    else if (arr[i] + arr[k] > 2*arr[j]) 
		    { 
                L[i][j] = 2;
                i--; 
            } 
    		else
	    	{ 
			    L[i][j] = L[j][k] + 1; 
                llap = max(llap, L[i][j]); 
                i--; 
                k++; 
		    } 
		} 
        // if k>=n 
		while (i>=0) 
		{ 
			L[i][j] = 2; 
			i--; 
		} 
	} 
	return llap; 
} 

// TC : O(N)    &   SC : O(N)
int longestAP2(int arr[], int n)
{
    if (n <= 2) 
        return n; 
  
    vector<int> llap(n, 2); 
    sort(arr, arr+n);

    int ans = INT_MIN;
    for(int j=n-2; j>=0; j--) 
    { 
        int i = j-1, k = j+1; 
        while (i>=0 && k<n) 
        { 
            if (arr[i] + arr[k] == 2*arr[j]) 
            { 
                llap[j] = max(llap[k]+1, llap[j]); 
                ans = max(ans, llap[j]); 
                i--; 
                k++; 
            } 
            else if (arr[i]+arr[k] < 2*arr[j]) 
                k++;
            else
                i--; 
        } 
    } 
    return ans; 
}

int main()
{
    int arr[] = {1,7,10,13,16};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of longest AP is :- "<<longestAP2(arr,size)<<endl;
}