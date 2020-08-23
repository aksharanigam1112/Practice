// Count of Smaller Numbers After Self
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(N^2)  &   SC : O(1)

// TC : O(N)   &   SC : O(N)
vector<int> countSmaller(int arr[], int n)
{
    deque<pair<int,int>>d;
    vector<int>ans(n,0);
    
    d.push_front({arr[n-1],0});
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] >= d.front().first)
        {
            int max_val=-1,count=0;
            while(!d.empty() && arr[i] > d.front().first)
            {
                max_val = max(max_val,d.front().second);
                d.pop_front();
                count++;
            }
            
            d.push_front({arr[i],max(max_val+1,count)});
            ans[i] = max(max_val+1,count);
        }
        else
        {
            d.push_front({arr[i],d.front().second});
            ans[i] =  d.front().second;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {0,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector<int>ans = countSmaller(arr,size);

    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
}