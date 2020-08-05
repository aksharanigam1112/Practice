// Given an unsorted array, find the length of the longest consecutive elements sequence.
// Input: [100, 4, 200, 1, 3, 2] Output: 4
// The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
#include<iostream>
#include<set>
using namespace std;

// Brute Force to use sorting and the check TC : O(NlogN)

// Using Hashing TC : O(N)  &  SC : O(N)
int longestSeq(int arr[], int size)
{
    set<int>hash; 
    int len=0; 
  
    for(int i=0; i<size; i++) 
        hash.insert(arr[i]); 
  
    for(int i=0; i<size; i++) 
    { 
        if(hash.find(arr[i]-1) == hash.end()) 
        { 
            int j = arr[i]; 
            while (hash.find(j) != hash.end()) 
                j++; 
            len = max(len, j-arr[i]); 
        } 
    } 
    return len; 
}

int main()
{
    int arr[] = {100,4,200,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of longest consecutive sequence is : "<<longestSeq(arr,n)<<endl;
}