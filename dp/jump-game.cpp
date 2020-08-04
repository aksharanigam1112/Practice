// Given an array, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
#include<iostream>
#include<climits>
using namespace std;

// Recursive Top Down       TC : O(N^N)  &  SC : O(N)
int jumpGameTD(int arr[], int size, int start)
{
    if(start==size-1)
        return 0;
    
    int jumps = INT_MAX;
    for(int i=arr[start];i>=1;i--)
    {
        if(i+start <= size-1)
        {   
            int ans = jumpGameTD(arr,size,start+i);
            if(ans!=INT_MAX)
                jumps = min(jumps,1+ans);      
        }
    }
    return jumps;
}


// Bottom UP    TC : O(N^2) &  SC : O(N)
int jumpGameBU(int arr[], int size)
{
    int jumps[size];
    jumps[size-1] = 0;

    for(int i=size-2;i>=0;i--)
    {
        int ans = INT_MAX;
        for(int j=arr[i];j>=1;j--)
        {
            if(j+i<=size-1)
                ans = min(ans,jumps[j+i]);
        }
        jumps[i] = ans!=INT_MAX ? 1+ans : INT_MAX;
    }
    return jumps[0];
}

// Greedy Approch TC : O(N)  &  SC : 0(1)
int minJumps(int arr[], int n) 
{ 
    if (n <= 1) 
        return 0; 
  
    if (arr[0] == 0) 
        return -1; 
  
    int maxReach = arr[0], step = arr[0], jump = 1; 
  
    for(int i=1; i<n; i++) 
    { 
        if(i == n - 1) 
            return jump; 
  
        maxReach = max(maxReach, i + arr[i]); 
        step--; 
        if (step == 0) 
        { 
            jump++; 
            if (i >= maxReach) 
                return -1; 
            step = maxReach - i; 
        } 
    } 
    return -1; 
} 
int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9 };
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min No of jumps required TD : "<<jumpGameTD(arr,size,0)<<endl;
    cout<<"Min No of jumps required BU : "<<jumpGameBU(arr,size)<<endl;
    cout<<"Min No of jumps required Greedy : "<<minJumps(arr,size)<<endl;
}