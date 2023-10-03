// Given a string s, return the lexicographically largest subsequence
// of s that contains all the distinct characters of s exactly once.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string lexicographicalLargest(string str) {

	map<char, int> count, visited;
	stack<char> s;

	for(int i=0;i<str.length();i++)
		count[str[i]]++;

	for(int i=0;i<str.length();i++) {

		count[str[i]]--;

		if(visited[str[i]])
			continue;

		while(!s.empty() && s.top() < str[i] && count[s.top()] > 0) {

			visited[s.top()] = 0;
			s.pop();
		}

		s.push(str[i]);
		visited[str[i]] = 1; 
	}


	string ans = "";
	while(!s.empty()) {
		ans = s.top() + ans;
		s.pop();
	}

	return ans;
}

int main() {
	// string str = "ababc";
	string str = "cbacdcbc";

	cout<<"Lexicographically largest subsequence with all unique characters : "<<lexicographicalLargest(str)<<endl;
}
