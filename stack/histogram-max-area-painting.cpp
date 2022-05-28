#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int heights_building_painted_area(vector<int>arr)
{
	deque<int> from_left, from_right;
	stack<pair<int,int>> s;
	int area = -1;

	// From left
	for(int i=0;i<arr.size();i++)
	{
		int val;

		if(s.empty() || arr[i] > s.top().first)
			val = i;
		
		
		while(!s.empty() && arr[i] <= s.top().first)
		{
			val = s.top().second;
			s.pop();
		}

		s.push({arr[i], val});
		from_left.push_back(val);
		
	}

	// Clear the stack
	while(!s.empty())
		s.pop();


	// From right
	for(int i=arr.size()-1; i>=0;i--)
	{
		int val;
		if(s.empty() || arr[i] > s.top().first)
			val = i;
	
			
		while(!s.empty() && arr[i] <= s.top().first)
		{
			val = s.top().second;
			s.pop();
		}

		s.push({arr[i], val});
		from_right.push_front(val);
	}


	// Calculate area
	for(int i=0;i<arr.size();i++)
	{
		auto left = from_left.front();
		auto right = from_right.front();

		int a = arr[i] * (right - left+ 1);

		cout<<arr[i]<<" "<<left<<" "<<right<<"\tArea : "<<a<<endl;
		area = max(area, a);

		from_left.pop_front();
		from_right.pop_front();
	}

	return area;
}


int main()
{
	vector<int> arr = {2,1,5,6,2,3};
	cout<<heights_building_painted_area(arr)<<endl;
}
