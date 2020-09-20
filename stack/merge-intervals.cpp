// Given a set of intervals merge all the ovrlapping intervals
// and print the new set of intevals.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct interval
{
    int start,end;
};

bool compare(interval &a, interval &b)
{
    return a.start < b.start ;
}

void print(stack<interval>&s)
{
    while(!s.empty())
    {
        cout<<"("<<s.top().start<<","<<s.top().end<<")"<<" ";
        s.pop();
    }
    cout<<endl;
}

void mergeIntervals(vector<interval>&arr)
{
    stack<interval>st;
    
    // Sorting the intervals based on their starting value
    sort(arr.begin(),arr.end(),compare);

    st.push(arr[0]);

    for(int i=1;i<arr.size();i++)
    {
        interval it = arr[i];

        if(it.start > st.top().end)
            st.push(it);
        
        if(st.top().end < it.end)
            st.top().end = it.end; 
    }
    print(st);
}

int main()
{
    vector<interval> arr =  {{1,5},{2,3},{4,6},{7,8},{8,10},{12,15}};
    cout<<"Merged Intervals are : ";
    mergeIntervals(arr);
}