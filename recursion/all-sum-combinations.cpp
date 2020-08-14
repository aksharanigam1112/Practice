#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void findcomb(vector<int>&arr,int target,int sum,vector<vector<int>>&ans
                    ,vector<int>&v,int index)
{
    if(sum==target)
    {
        ans.push_back(v);
        return;
    }
        
    for(int i=index+1;i<arr.size();i++)
    {
        if(sum+arr[i]<=target)
        {
            sum+=arr[i];
            v.push_back(arr[i]);
                
            findcomb(arr,target,sum,ans,v,i);
                
            sum-=arr[i];
            v.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>&candidates, int target) 
{
    // To avoid duplicate copies [2,1,5],[1,2,5] etc
    // Create the set for the given vector 
    vector<vector<int>>ans;
    vector<int>v;
    findcomb(candidates,target,0,ans,v,-1);
    return ans;
}

int main()
{
    vector<int>arr = {10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>>ans = combinationSum(arr,target);

    for(auto it : ans)
    {
        for(auto i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}