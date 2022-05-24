// Minimum substring with all chars from a given pattern
// For example : s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Sliding window concept
#include<iostream>
#include<string>
#include<map>
#define INF 9999999
using namespace std;

string min_window_substring(string str, string pat)
{
	map<char, int>m;
	int i=0, start=-1, window_len=INF, count=0;
	
	// Create a map of the characters in pattern
	for(char c : pat)
	{
		m[c]++;
	}
	count = m.size();

	for(int j=0;j<str.length();j++)
	{
		if(m.find(str[j]) != m.end())
		{
			m[str[j]]--;
			if(m[str[j]] == 0)
				count--;
		}

		// If the window contains all the elements of the pattern
		if(count == 0)
		{
			// Reduce the window size, as far as count is still 0
			while(i<=j && count == 0)
			{
				if(j-i+1 < window_len)
				{
					window_len = j-i+1;
					start = i;
				}

				// If the left char (i) belongs to map, increase its value
				if(m.find(str[i]) != m.end())
				{
					m[str[i]]++;
					if(m[str[i]] == 1)
						count++;	
				} 
				
				i++;
			}
		}
	}

	if(start == -1)
		return "";

	return str.substr(start, window_len);

}


int main()
{
	// string pat = "ADOBECODEBANC", str = "ABC";
	string str = "ABAACBAB", pat = "ABC";
	string ans = min_window_substring(str, pat);
	cout<<ans<<" "<<ans.length()<<endl;
}