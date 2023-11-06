// Given an array of intervals where intervals[i] = [starti, endi], 
// return the min no. of intervals you need to remove to make the rest of the intervals non-overlapping.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V vector<int> 

// sort asc on the end time
bool compare(V v1, V v2) {
    return v1[1] < v2[1];
}

void print(vector<V> arr){
    for(V i : arr) {
        cout<<"("<<i[0]<<","<<i[1]<<")";
    }
    cout<<endl;
}

int eraseOverlapIntervals(vector<V>& arr) {
    
    sort(arr.begin(), arr.end(), compare);
    // print(arr);

    int prev = 0, count = 0;

    for(int i=1;i<arr.size();i++) {

        if(arr[i][0] < arr[prev][1])
            count++;
        else 
            prev=i;
    }

    return count;
}

int main() {
	// vector<V> arr = {
	// 	{1,100},{11,22},{1,11},{2,12}
	// };

	vector<V> arr = {
		{0,2},{1,3},{2,4},{3,5},{4,6}
	};

	cout<<"Count of intervals to remove : "<<eraseOverlapIntervals(arr)<<endl;
}
