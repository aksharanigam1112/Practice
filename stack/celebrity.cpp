// In a party of N people, only one person is known to everyone (Celebrity). 
// While the celebrity doesn’t know anyone at the party. 
// Find the celebrity in the minimum number of steps.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Ignore diagonal

// 1. BRUTE FORCE : Parse every row & check which row has all 0's (let's say its A), 
// The column of A will have all 1's except where row = col = A (diagonal element), hence celebrity found
// TC : O(N^2) 


// 2. OPTIMIZED USING STACK : push all N people in the stack,
// Pop the first 2 & check : 
	// if A knows B => Then discard A & push back B
	// If B knows A => Then discard B & push back A
// Continue till you have only 1 element left in the stack, & check its row is all 0's & col is all 1's
// TC : O(N) &  SC : O(N)
int celebrity(vector<vector<int>> arr, int n) {
	stack<int> s;
	
	for(int i=0;i<n;i++)
		s.push(i);
	
	while(s.size() > 1) {

		int a = s.top();
		s.pop();

		int b = s.top();
		s.pop();

		// A knows B
		if (arr[a][b] == 1)
			s.push(b);

		// B knows A
		if(arr[b][a] == 1)
			s.push(a);
	}

	int celeb = s.top();
	s.pop();

	// Check arr[celeb][col] == 0 && arr[row][celeb] == 1
	for (int i=0; i<n; i++) {
        
        if (i != celeb) {
            if (arr[i][celeb] == 0 || arr[celeb][i] == 1)
                return -1;
        }
    }

	return celeb;
}	


// 3. OPTIMIZED USING 2 POINTERS
// TC : O(N) & SC : O(1)
int celebrity2(vector<vector<int>> arr, int n) {
	int a = 0, b = n-1;

	while(a<b) {
		// A knows B 
		if(arr[a][b] == 1)
			a++;

		// A does not knows B
		else 
			b--;
	}

	int celeb = a;
	for (int i=0; i<n; i++) {
        
        if (i != celeb) {
            if (arr[i][celeb] == 0 || arr[celeb][i] == 1)
                return -1;
        }
    }

    return celeb;
}



int main() {
	vector<vector<int>> arr = {
		{ 0, 0, 1, 0 },
	    { 0, 0, 1, 0 },
      	{ 0, 0, 0, 0 },
      	{ 0, 0, 1, 0 }
	};

	// int ans = celebrity(arr, arr.size());
	int ans = celebrity2(arr, arr.size());
	if (ans == -1) 
		cout<<"Celebrity does not exist"<<endl;
	
	else 
		cout<<"Celebrity is : "<<ans+1<<endl;
}
