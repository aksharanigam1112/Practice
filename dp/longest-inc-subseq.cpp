#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE      TC : O(N^(N+1)) SC : O(N)

int maxSeqLenBF(int arr[], int index , int size)
{
    if(index>=size)
        return 0;
    int maxLen = 1;

    for(int i=index+1;i<=size;i++)
    {
        if(arr[i]>=arr[index])
        {
            maxLen = max(maxSeqLenBF(arr,i,size)+1,maxLen);
        }
    }
    return maxLen;
}


// TOP-DOWN  TC : O(N^2) SC : O(N)

int maxSeqLenTD(int arr[] , int index, int size , int result[])
{
    if(index>=size)
        return 0;

    if(result[index]<0)
    {
        int maxLen=1;
        for(int i=index+1;i<size;i++)
        {
            if(arr[i]>=arr[index])
            {
                maxLen = max(maxSeqLenBF(arr,i,size)+1,maxLen);
            }
        }
        result[index] = maxLen;
    }
    
    return result[index];
}

// BOTTOM UP    TC : O(N^2) SC : O(N)

int maxSeqLenBU(int arr[], int size)
{
    int result[size]; 
   
    result[0] = 1;    

    for (int i = 1; i < size; i++ )  
    { 
        result[i] = 1; 
        for (int j = 0; j < i; j++ )
        {   
            if ( arr[i] > arr[j] && result[i] < result[j] + 1)  
                result[i]++;
        }  
    } 
  
    return *max_element(result, result+size); 
}



int maxSeq(int arr[],int size)
{
    int maxLen=0;
    int result[size];

    for(int i=0;i<size;i++)
    {
        result[i]=-1;
    }
    
    for(int i=0;i<size;i++)
    {
        // maxLen = max(maxSeqLenBF(arr,i,size),maxLen);
        maxLen = max(maxSeqLenTD(arr,i,size,result),maxLen);
    }
    return maxLen;
}



int main()
{
    int arr[] = {12,10,18,4,6,9,15,3,11,17,8};
    int n = sizeof(arr)/sizeof(arr[0]);
        
    cout<<"Max length :- "<<maxSeq(arr,n)<<endl;
}