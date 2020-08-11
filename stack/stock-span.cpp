// Total no. of days price is greater than prev 
// 1) For prev(left elements only)
// 2) For both left & right.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(N^2)

// Using Stack TC : O(N)    &    SC : O(N)
int stockSpan1(int arr[], int size)
{
    stack<pair<int,int>>st;
    int span=1;
    st.push(make_pair(arr[0],0));

    for(int i=1;i<size && !st.empty();i++)
    {
        auto ele = st.top();
        // cout<<ele.first<<" "<<ele.second<<endl;
        int pos=i;
        while(arr[i]>ele.first && !st.empty())
        {
            st.pop();
            pos = ele.second;
            // cout<<"Popped element : "<<ele.first<<" "<<ele.second<<endl;
            span = max(span,(i-pos+1));
            
            if(!st.empty())
                ele = st.top();
        }
        st.push(make_pair(arr[i],pos));

        if(arr[i] < ele.first)
            st.push(make_pair(arr[i],i));
    }
    return span;
}

int main()
{
    int arr[] = {5,10,8,6,12,9,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max stock span length (from left only) : "<<stockSpan1(arr,size)<<endl;
    // cout<<"Max stock span length (both sides) : "<<stockSpan2(arr,size)<<endl;
}