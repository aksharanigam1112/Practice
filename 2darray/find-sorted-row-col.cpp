// Find element in sorted row and column
#include<iostream>
using namespace std;
#define n 4

// TC : O(N) SC : O(1)
void search(int mat[n][n], int x) 
{ 
	int i = 0, j = n-1;
  
    while (i<n && j >= 0) 
    { 
        if (mat[i][j] == x) 
        { 
            cout<<"Found at : ("<<i<<","<<j<<")"<<endl; 
            return; 
        } 
        if (mat[i][j] > x) 
            j--; 
        else 
            i++; 
    } 
  
    cout<<"Element not found"<<endl; 
        return;  
} 

int main() 
{ 
	int mat[n][n] = { { 10, 20, 30, 40 }, 
					{ 15, 25, 35, 45 }, 
					{ 27, 29, 37, 48 }, 
					{ 32, 33, 39, 50 } }; 
	search(mat,29); 
} 

