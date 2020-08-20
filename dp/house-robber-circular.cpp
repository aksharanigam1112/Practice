#include<iostream>
using namespace std;
   int rob(int nums[], int size) 
    {
        if(size==0)
            return 0;
        if(size==1)
            return nums[0];
        
        if(size==2)
            return max(nums[0],nums[1]);
        
    
        int dp[size];
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = max(nums[0],nums[1]);
        
        for(int i=3;i<size;i++)
        {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[size-1];
    }

int main()
{
    int arr[] = {1,2,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max possible stealing : "<<rob(arr,size)<<endl;
}