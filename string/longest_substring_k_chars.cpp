// Find the longest substring of a string containing k distinct characters
// Variable Sliding Window Concept
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longest_substring_k_distinct_chars(string str, int k)
{
	int i=0, start=-1, size=0;
	map<char, int> window;


	for(int j=0;j<str.length();j++)
	{
		// Increase the window
		window[str[j]]++;

		// Since we are allowed only K distinct characters 
		if(window.size() == k)
		{
			size = max(j-i+1, size);
			start = i;
		}

		// Remove the charcters from left (i) if the distinct characters is more than K
		while(window.size() > k)
		{
			window[str[i]]--;
			if(window[str[i]] == 0)
				window.erase(str[i]);
			i++;
		}
		
	}

	return str.substr(start, size);
}


int main()
{
	string s = "aabbcccmmmabcd";
	int k=3;

	string ans = longest_substring_k_distinct_chars(s,k);
	cout<<ans<<" "<<ans.length()<<endl;

	return 0;
}