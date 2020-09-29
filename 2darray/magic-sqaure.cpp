// Sum of all the rows = Sum of all the cols = Sum of the diagonals = n*(n^2+1)/2
// A magic square contains the integers from 1 to n^2. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generateSquare(int n)  
{  
    int magicSquare[n][n];  
    memset(magicSquare, 0, sizeof(magicSquare));  
  
    int i = n/2 , j = n-1;  
  
    for(int num = 1; num<=n*n; )  
    {  
        if (i == -1 && j == n)   
        {  
            j = n-2;  
            i = 0;  
        }  
        else
        {  
            if (j == n)  
                j = 0;  
  
            if (i < 0)  
                i = n - 1;  
        }  
        if (magicSquare[i][j])   
        {  
            j -= 2;  
            i++;  
            continue;  
        }  
        else
            magicSquare[i][j] = num++;  
  
        j++; i--;  
    }  
  
    cout<<"The Magic Square is :"<<endl;  
    for (i = 0; i < n; i++)  
    {
        for (j = 0; j < n; j++)  
            cout<<magicSquare[i][j]<<" ";  
        cout<<endl; 
    }  
}  

int main()
{
    int n = 5;
    generateSquare(n);
}