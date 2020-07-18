#include<iostream>
#include<math.h>
#define MAX 1000000
using namespace std;

// 1st Approach Brute Force TC : O(2^N)

int exchangeBF1(int arr[],int N,int last)
{
    if(N==0)
        return 0;
    if(N<0 || last<0)
        return  MAX;
    
    int incl = 1+exchangeBF1(arr,N-arr[last],last-1);
    int ecl = exchangeBF1(arr,N,last-1);

    return min(incl,ecl);
}

// 2nd Approach Brute Force 

int exchangeBF2(int arr[] , int N , int index)
{
    if(N==0)
        return 0;
    if(N<0 || index<0)
        return MAX;

    int min_coins = MAX;
    for(int i=index;i>=0;i--)
    {
        min_coins = min(min_coins , 1+exchangeBF2(arr,N-arr[i] , i-1));
    }
    return min_coins;
} 

// Bottom Up TC : O(N^2)
int exchangeBU(int arr[], int N , int size)
{
    int results[size][N+1];

    // fill 1st row
    for(int i=0;i<=N;i++)
    {
        if(arr[0] == i)
            results[0][i] = 1;
        else
            results[0][i] = MAX;
    }

    //fill 1st col
    for(int i=0;i<size;i++)
        results[i][0] = 0;

    for(int i=1;i<size;i++)
    {
        for(int j=1;j<=N;j++)
        {
            results[i][j] = min(results[i-1][j] , j-arr[i]<0 ? MAX : 1+results[i-1][j-arr[i]]);
        }
    }

    return results[size-1][N];
}

int main()
{
    int arr[] = {2,2,5,5,7,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int N = 10;

    cout<<"Min coins required BF1 :- "<<exchangeBF1(arr,N,size-1)<<endl;
    cout<<"Min coins required BF2 :- "<<exchangeBF2(arr,N,size-1)<<endl;
    cout<<"Min coins required BU :- "<<exchangeBU(arr,N,size)<<endl;
    
}