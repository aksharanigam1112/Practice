#include<iostream>
#include<math.h>
#define n 3
using namespace std;

void rotate(int matrix[n][n])
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

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[n][n] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    
    rotate(arr);

}