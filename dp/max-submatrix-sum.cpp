#include<iostream>
#include<bits/stdc++.h> 
#define ROW 4 
#define COL 5 
using namespace std; 

int kadane(int* arr, int* start, int* finish, int n) 
{ 
	int sum = 0, maxSum = INT_MIN, i; 

	*finish = -1; 

	int local_start = 0; 

	for (i = 0; i < n; ++i) 
	{ 
		sum += arr[i]; 
		if (sum < 0) 
		{ 
			sum = 0; 
			local_start = i + 1; 
		} 
		else if (sum > maxSum) 
		{ 
			maxSum = sum; 
			*start = local_start; 
			*finish = i; 
		} 
	} 

	if (*finish != -1) 
		return maxSum; 

	maxSum = arr[0]; 
	*start = *finish = 0; 

	for (i = 1; i < n; i++) 
	{ 
		if (arr[i] > maxSum) 
		{ 
			maxSum = arr[i]; 
			*start = *finish = i; 
		} 
	} 
	return maxSum; 
} 

void findMaxSum(int arr[ROW][COL]) 
{ 
	int maxSum = INT_MIN,cs,ce,rs,re; 

	int temp[ROW], sum, start, finish; 

	for(int left=0; left<COL; left++) 
	{ 
		memset(temp, 0, sizeof(temp)); 

		for (int right=left; right<COL; right++) 
		{ 
			for (int i = 0; i < ROW; ++i) 
				temp[i] += arr[i][right]; 

			sum = kadane(temp, &start, &finish, ROW); 

			if (sum > maxSum) 
			{ 
				maxSum = sum; 
				cs = left; 
				ce = right; 
				rs = start; 
				re = finish; 
			} 
		} 
	} 

	cout<<"(Rs,Cs) : ("<<rs<<","<<cs<<")"<< endl; 
	cout<<"(Re,Ce) : ("<<re <<","<<ce<<")"<< endl; 
	cout<<"Max sum is: " <<maxSum<< endl; 
} 

int main() 
{ 
	int arr[ROW][COL] = {{1, 2, -1, -4, -20}, 
					{-8, -3, 4, 2, 1}, 
					{3, 8, 10, 1, 3}, 
					{-4, -1, 1, 7, -6}}; 

	findMaxSum(arr);  
} 
