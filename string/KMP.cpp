#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void KMP(string s1, string s2)
{
    int m = s1.length();
	int n = s2.length();

	// if s2 is an empty string
	if (n == 0)
	{
		cout << "Pattern occurs with shift 0";
		return;
	}

	// if s1's length is less than that of s2's
	if (m < n)
	{
		cout << "Pattern not found";
		return;
	}

	// next[i] stores the index of next best partial match
	int next[n + 1];

    memset(next,0,sizeof(next));

	for (int i=1; i<n; i++)
	{
		int j = next[i + 1];

		while (j > 0 && s2[j] != s2[i])
			j = next[j];

		if (j > 0 || s2[j] == s2[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		if (s1[i] == s2[j])
		{
			if (++j == n)
				cout << "Pattern occurs with shift " << i - j + 1 << endl;
		}
		else if (j > 0) 
        {
			j = next[j];
			i--;	// since i will be incremented in next iteration
		}
	}
}

int main()
{
    string text = "ABCABAABCABAC" , pattern = "CAB";
	KMP(text, pattern);
}