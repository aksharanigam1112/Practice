#include<iostream>
#include<vector>
#include<stack>
#define INF -99999
using namespace std;

vector<int> nearest_smallest(vector<int> arr)
{
	stack<int> s;
	vector<int> ans;

	s.push(arr[0]);
	ans.push_back(INF);

	for(int i=1;i<arr.size();i++)
	{
		while(!s.empty() && s.top() > arr[i])
			s.pop();
		
		int val = !s.empty() ? s.top() : INF;	
		ans.push_back(val);

		s.push(arr[i]);

	}
	return ans;

}


int main()
{
	vector<int> arr = {1,6,4,10,2,5};
	// vector<int> arr = {6,8,4,7,12,9,3,15,10,2};
	
	vector<int> ans = nearest_smallest(arr);
	for(int i : ans)
	{
		if(i == INF)
			cout<<"_"<<", ";
		else
			cout<<i<<", ";
	}
	cout<<endl;

}