#include<iostream>
#include<math.h>
#define n 3
using namespace std;

void print(int matrix[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

void rotate90Clockwise(int matrix[n][n])
{
    int y = n - 1;
    
    for (int i=0; i<n/2; i++) 
    {
        for (int j = i; j < y-i; j++) 
        {
            int k = matrix[i][j];

            matrix[i][j] = matrix[y - j][i];
            matrix[y - j][i] = matrix[y - i][y - j];
            matrix[y - i][y - j] = matrix[j][y - i];
            matrix[j][y - i] = k;
        }
    }
    print(matrix);
}

void transpose(int arr[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
            swap(arr[i][j], arr[j][i]);
    }
}

void reverseCol(int arr[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0,k=n-1;j<k;j++,k--)
            swap(arr[j][i],arr[k][i]);
    }
}

void rotate90Anticlockwise(int matrix[n][n])
{
    // Transpose a matrix first i.e Row <---> Col
    // Then reverse the cols
    transpose(matrix);
    reverseCol(matrix);
    print(matrix);
}

int main()
{
    int arr[n][n] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    
    cout<<"Actual Matrix : "<<endl;
    print(arr);

    cout<<"Reverse matrix 90 degrees clockwise : "<<endl;
    rotate90Clockwise(arr);

    cout<<"Reverse matrix 90 degrees anti-clockwise : "<<endl;
    rotate90Anticlockwise(arr);

}