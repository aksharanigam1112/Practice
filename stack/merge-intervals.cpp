// Given a set of intervals merge all the ovrlapping intervals
// and print the new set of intevals.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
};

// Sort ascending order
bool compare(Interval p1, Interval p2) {
    return p1.start < p2.start;
}

void print(vector<Interval> arr){
    for(Interval i : arr) {
        cout<<"("<<i.start<<","<<i.end<<")";
    }
    cout<<endl;
}

// TC : O(N) & SC : 0(N)
vector<Interval> mergeOverlappingInterval(vector<Interval> arr) {
    if (arr.empty())
        return vector<Interval>();

    sort(arr.begin(), arr.end(), compare);

    stack<Interval> s;
    s.push(arr[0]);

    for(int i=1;i<arr.size();i++) {

        // Current overlaps with top, then update top end time 
        if(arr[i].start <= s.top().end)
            s.top().end = max(s.top().end, arr[i].end);

        else
            s.push(arr[i]);
    }

    vector<Interval>ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
} 

// TC : O(N) & SC : 0(1)
vector<Interval> mergeOverlappingInterval2(vector<Interval> arr) {
    if (arr.empty())
        return vector<Interval>();

    sort(arr.begin(), arr.end(), compare);
    
    int prev = 0;

    for(int i=1;i<arr.size();i++) {

        // Current i overlaps with previous index
        if(arr[i].start <= arr[prev].end)
            arr[prev].end = max(arr[prev].end, arr[i].end);

        else {
            prev++;
            arr[prev] = arr[i];
        }
    }

    vector<Interval> ans(arr.begin(), arr.begin()+prev+1);
    return ans;
} 

int main()
{
    vector<Interval> arr =  {{1,5},{2,3},{4,6},{7,8},{8,10},{12,15}};
    
    // vector<Interval> ans = mergeOverlappingInterval(arr);

    vector<Interval> ans = mergeOverlappingInterval2(arr);
    print(ans);
}
