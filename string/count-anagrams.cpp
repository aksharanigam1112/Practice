// Count the no. of anagrams present in a string for a given pattern. 
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Sliding window based

#include <iostream>
#include <map>
#include <string>
using namespace std;

int count_anagrams(string str, string word) {
	map<char,int> hash;
	int k = word.size();

	for(char c : word)
		hash[c]++;
	
	int start = 0, ans = 0, count = hash.size();
	for(int i=0;i<str.length();i++) {

		// If the char matches the word
		if(hash.find(str[i]) != hash.end()) {
			hash[str[i]]--;

			count -= hash[str[i]] == 0 ? 1 : 0;
		}
 
		if(i-start+1 == k) {

			// if count of distinct chars in hash is 0 => anagram found
			if(count == 0)
				ans++;

			// Re-initialize the hash map for the start element
			if(hash.find(str[start]) != hash.end()) {
				hash[str[start]]++;

				count += hash[str[start]] == 1 ? 1 : 0;
			}
			
            start++;
		}
	}

	return ans;
}



int main(){
	string txt = "aabaabaa", pat = "aaba";
	// string txt = "forxxorfxdofr", pat = "for";
	cout<<count_anagrams(txt, pat)<<endl;
}
