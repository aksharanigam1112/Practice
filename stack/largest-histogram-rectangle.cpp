// Find the area of largest rectangle formed by the histogram heights.
// Hint : It expands both left & right
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(N) & SC : O(N+N)
class Histogram
{
    private: 
    vector<int>left, right;

    void nextSmaller(int arr[], int n) {
        stack<int> s;
        s.push(-1);

        right.resize(n, -1);

        for(int i=n-1;i>=0;i--) {

            while(s.top() !=-1 && arr[s.top()] >= arr[i])
                s.pop();
            
            right[i] = s.top();
            s.push(i);
        }
    }

    void prevSmaller(int arr[], int n) {
        stack<int> s;
        s.push(-1);

        left.resize(n, -1);

        for(int i=0;i<n;i++) {

            while(s.top() !=-1 && arr[s.top()] >= arr[i])
                s.pop();
            
            left[i] = s.top();
            s.push(i);
        }
    }

    public:

    int largestRectangle(int arr[], int size){
        nextSmaller(arr, size);
        prevSmaller(arr, size);

        int maxArea = INT_MIN;
        for(int i=0;i<size;i++) {

            int l = arr[i];
            if(right[i] == -1)
                right[i] = size;

            int b = right[i] - left[i] - 1;
            maxArea = max(maxArea, l*b);
        }

        return maxArea;
    }
    
};

// Optimizes space complexity 
// TC : O(N) & SC : O(N)
int heights_building_area_from_left(int arr[], int len)
{
    // 1st pos -> value & 2ns pos is the index
    stack<pair<int,int>> s;
    int area = -1;

    for(int i=0;i<len;i++)
    {
        pair<int,int>val;
        
        if(s.empty() || arr[i] > s.top().first)
            val = {arr[i], i}; 

        while(!s.empty() && arr[i] <= s.top().first)
        {
            val = s.top();
            s.pop();
            area = max(area, val.first * (i - val.second));
        }

        s.push({arr[i], val.second});
        
    }

    while(!s.empty())
    {
        auto val = s.top();
        area = max(area, val.first * (len-val.second));
        s.pop();
    }

    return area;
}

int main()
{
    int heights[] = {2,1,5,6,2,3};
    int size = sizeof(heights)/sizeof(heights[0]);
    
    Histogram h;
    cout<<"Max area formed by histograms : "<<h.largestRectangle(heights,size)<<endl;
    cout<<"Max area formed by histograms optimized : "<<heights_building_area_from_left(heights, size)<<endl;
}
