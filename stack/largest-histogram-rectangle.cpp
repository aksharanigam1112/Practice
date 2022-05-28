// Find the area of largest rectangle formed by the histogram heights.
// Hint : It expands both left & right
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Histogram
{
    private: 
    vector<int>l,r;

    void fromLeft(int arr[], int size)
    {
        stack<pair<int,int>>s;
        
        for(int i=0;i<size;i++)
        {
            if(s.empty())
            {
                l.push_back(-1);
                s.push({arr[i],i});
            }
            else
            {
                while(!s.empty() && s.top().first>=arr[i])
                    s.pop();
                if(s.empty())
                    l.push_back(-1);
                else
                    l.push_back(s.top().second);
                s.push({arr[i],i});
            }
        }
    }

    void fromRight(int arr[], int size)
    {
        stack<pair<int,int>>s;
        
        for(int i=size-1;i>=0;i--)
        {
            if(s.empty())
            {
                r.push_back(size);
                s.push({arr[i],i});
            }
            else
            {
                while(!s.empty() && s.top().first>=arr[i])
                    s.pop();
                if(s.empty())
                    r.push_back(size);
                else 
                    r.push_back(s.top().second);
                s.push({arr[i],i});
            }
        }
        reverse(r.begin(),r.end());
    }

    public:

    int largestRectangle(int arr[], int size)
    {
        fromLeft(arr,size);
        fromRight(arr,size);
        int area=0;

        for(int i=0;i<size;i++)
        {
            int val = (r[i]-l[i]-1)*arr[i];
            area = max(area,val);
        }
        return area;
    }
};

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
    cout<<"Max area formed by histograms : "<<heights_building_area_from_left(heights, size)<<endl;
}
