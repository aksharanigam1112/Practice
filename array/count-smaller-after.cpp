// Count of Smaller Numbers After Self
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(N^2)  &   SC : O(1)

// TC : O(N)   &   SC : O(N)
vector<int> countSmallerRight(int arr[], int len) 
{ 
	multiset<int> s; 
	vector<int>countSmaller(len); 
    
	for (int i=len-1; i>=0; i--) 
    { 
		s.insert(arr[i]); 
        // Find the first element that is lower than arr[i]
		auto it = s.lower_bound(arr[i]); 
        // Find the distance between above found element and the beginning of the set
        // & store the distance 
		countSmaller[i] = distance(s.begin(), it); 
	}
    return countSmaller; 
} 

int main()
{
    int arr[] = {0,2,1,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector<int>ans = countSmallerRight(arr,size);

    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
}