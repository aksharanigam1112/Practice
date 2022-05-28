int heights_building_painted_area(vector<int>arr)
{
	deque<pair<int,int>> from_left, from_right;
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
		from_left.push_back({arr[i], val});
		
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
		from_right.push_front({arr[i], val});
	}


	// Calculate area
	while(!from_left.empty() && !from_right.empty())
	{
		auto left = from_left.front();
		auto right = from_right.front();

		int a = left.first * (right.second - left.second + 1);

		cout<<"("<<left.first<<","<<left.second<<") ("<<right.first<<","<<right.second<<") \tArea : "<<a<<endl;
		area = max(area, a);

		from_left.pop_front();
		from_right.pop_front();
	}

	return area;
}
