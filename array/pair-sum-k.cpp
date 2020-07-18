#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE O(N^2)

// void findPair(int arr[] , int len, int sum)
// {
//     for(int i=0;i<len-1;i++)
//     {
//         for(int j=i+1;j<len;j++)
//         {
//             if(arr[i]+arr[j] == sum)
//                 cout<<arr[i]<<" "<<arr[j]<<endl;
//         }
//     }
// }


//OPTIMIZED TO O(N) using hashing

void findPair(int arr[] , int len , int sum)
{
    unordered_set<int>hash;
   
    for(int i=0;i<len;i++)
    {
        if(hash.find(sum-arr[i]) !=hash.end())
            cout<<arr[i]<<" "<<sum-arr[i]<<endl;       
        hash.insert(arr[i]);
    }
}



int main()
{
    int arr[] = {1,2,3,4,6};
    int sum = 7;
    findPair(arr,5,sum);
    return 0;
}