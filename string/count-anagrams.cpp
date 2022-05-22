// Count the no. of anagrams present in a string for a given pattern. 
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Sliding window based

#include <iostream>
#include <map>
#include <string>
using namespace std;

int count_anagrams(string str, string pat)
{
	map<char,int> m;
	int count, i=0,j=0, ans=0, k=pat.length();

	// Fill the map for the given pattern
	for(char c : pat)
		m[c]++;
	
	count = m.size();

	for(int j=0;j<str.length();j++) 
	{
		// If the char of string is present in the window, decrease its value from the map 
		if (m.find(str[j]) != m.end())
		{
			m[str[j]]--;
			if(m[str[j]] == 0)
				count--;
		}

		// When window length hasn't breached yet, but in next iteration it will increase
		// Reduce the window size
		if(j-i+1 == k)
		{
			ans += (count==0) ? 1 : 0;
            if(m.find(str[i]) != m.end()) 
            {
                m[str[i]]++;
                if(m[str[i]] == 1)
                    count++;
            }
			i++;
		}
	}

	return ans;
}



int main()
{
	string txt = "aabaabaa", pat = "aaba";
	// string txt = "forxxorfxdofr", pat = "for";
	cout<<count_anagrams(txt, pat)<<endl;
}

