#include<iostream>
#define MAX 10000
using namespace std;

// Brute Force TC : O(2^N)
bool subsetSumBF(int arr[] , int size , int index , int sum)
{
    if(index>size || sum<0)
        return false;

    if(sum==0)
        return true;

    return (subsetSumBF(arr,size,index+1,sum-arr[index]) || subsetSumBF(arr,size,index+1,sum));
}

// Bottom Up TC : O(N^2)
bool subsetSumBU(int arr[] , int size , int sum )
{
    bool result[size+1][sum+1];

    //Fill 1st row
    for(int i=0;i<=sum;i++)
        result[0][i] = false;

    // Fill 1st col
    for(int i=0;i<=size;i++)
        result[i][0] = true;
    
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-arr[i]<0)
                result[i][j] = false;
            // else if(j==arr[i])
            //     result[i][j] = true;
            else
            {
                result[i][j] = result[i-1][j] || result[i-1][j-arr[i]];
            }
        }
    }

    cout<<endl;
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return result[size][sum];
}

int main()
{
    int arr[]= {5,4,2};
    int size = sizeof(arr)/sizeof(arr[0]) , sum = 11;
    cout<<"Susbset sum exists or not BF :- "<<subsetSumBF(arr,size,0,sum)<<endl;
    cout<<"Susbset sum exists or not BU :- "<<subsetSumBU(arr,size,sum)<<endl;
}