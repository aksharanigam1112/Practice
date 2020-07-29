// Fill entire ith row and jth column with 0’s, if arr[i][j] is 0.
#include<iostream>
#define R 3
#define C 4
using namespace std;

// Brute Force to store all the i,j pos where 0 is encountered
// TC : O(R*C)  &    SC : O(R+C)


// TC : O(R*C)  &   SC : O(1)
void setZeroes(int matrix[R][C]) 
{
    bool isCol = false;

    for (int i = 0; i < R; i++) 
    {
        if (matrix[i][0] == 0) 
            isCol = true;

        for (int j = 1; j < C; j++) 
        {
            // If an element is zero, we set the first element of the 
            // corresponding row and column to 0
            if (matrix[i][j] == 0) 
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i=1; i<R; i++) 
    {
        for (int j=1; j<C; j++) 
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                matrix[i][j] = 0;
        }
    }

    if (matrix[0][0] == 0) 
    {
        for (int j = 0; j < C; j++)
            matrix[0][j] = 0;
      
    }

    // See if the first column needs to be set to zero as well
    if (isCol) 
    {
        for (int i = 0; i < R; i++) 
            matrix[i][0] = 0;
      
    }
}

void print(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[R][C] = {{0,1,2,0},
                    {3,4,5,2},
                    {1,3,1,5}};
    setZeroes(arr);
    print(arr);
}
