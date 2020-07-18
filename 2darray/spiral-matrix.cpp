#include<iostream>
using namespace std;

int main()
{
    int arr[4][5] = {{1,2,3,4,},{5,6,7,8},{9,10,11,12}};

    int m=3,n=4;
    int i=0,j=0,k=0,layer=0;

    while(k<m*n)
    {
        while(j<n-layer && arr[i][j]>0)
        {
            cout<<arr[i][j]<<" ";
            arr[i][j]= -arr[i][j];
            k++;
            j++;
        }

        j = n-1-layer;
        i++;
        
        while(i<m-layer && arr[i][j]>0)
        {
            cout<<arr[i][j]<<" ";
            arr[i][j]= -arr[i][j];
            i++;
            k++;
        }

        i--;
        j--;

        while(j>=layer &&arr[i][j]>0)
        {
            cout<<arr[i][j]<<" ";
            arr[i][j]= -arr[i][j];
            j--;
            k++;
        }

        j++;
        i--;
        layer++;
        while(i>=layer && arr[i][j]>0)
        {
            cout<<arr[i][j]<<" ";
            arr[i][j]= -arr[i][j];
            i--;
            k++;
        }
        i++;
        j++;
        cout<<endl;
    }
}