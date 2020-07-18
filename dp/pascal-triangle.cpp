#include<iostream>
#define n 7
using namespace std;

void pascal(int arr[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0 || i==j)
                arr[i][j]=1;
            else if(j<i)
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            else
                arr[i][j]=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[n][n];
    cout<<"Pascal Triangle : "<<endl;
    pascal(arr);
}