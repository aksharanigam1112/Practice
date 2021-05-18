#include<iostream>
#include<math.h>
#define MAX 100000
using namespace std;


// Brute Force TC : O(N^N)
int exchangeBF(int arr[],int N,int size)
{
    if(N==0)
        return 0;

    int min_coins = MAX;

    for(int i=0;i<size;i++)
    {
        if (arr[i] <= N)
        {
            int sub_res = exchangeBF(arr, N-arr[i],size); 
            min_coins = min(min_coins , sub_res+1);
        }      
    }
    return min_coins;
}

// Bottom Up TC : O(N^2) SC : O(N^2)
int exchangeBU(int arr[] , int N , int size )
{
    int results[size][N+1];

    for(int i=0;i<=N;i++)
        results[0][i] = floor(i/arr[0]);

    for(int i=0;i<size;i++)
        results[i][0] = 0;
    

    for(int i=1;i<size;i++)        // Coins available
    {
        for(int j=1;j<=N;j++)       // Sum we want to make
        {
            results[i][j] = min(results[i-1][j] , 1+results[i][j-arr[i]]);
        }
    }
    
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<=N;j++)
        {
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }

    return results[size-1][N];
}


int main()
{
    int arr[] = {1,2,5,7};
    int N = 9 , size = 4 ;
   
    cout<<"Min coins required :- "<<exchangeBF(arr,N,size)<<endl;
    cout<<"Min coins required :- "<<exchangeBU(arr,N,size)<<endl;
}