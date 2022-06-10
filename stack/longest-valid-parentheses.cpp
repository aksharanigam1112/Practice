#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

// TC : O(N) & SC : O(N)
int longestValidParentheses1(string str) 
{      
	if(str == "") 
		return 0;

	stack<int> s;
	int result = 0;
	s.push(-1);

	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '(')
			s.push(i);
		else
		{
			if(!s.empty())
				s.pop();
			if(!s.empty())
				result = max(result, i-s.top());
			else
				s.push(i);
		}
	}
	return result;

}

// TC : O(N) & SC : O(1)
int longestValidParentheses2(string str) 
{      
	if(str == "") 
		return 0;

	int result = 0, left=0, right=0;
	
	// From left to right 
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '(')
			left++;
		else
			right++;
			
		if(left == right)
			result = max(result, 2*left);
		else if(right > left)
			left = right = 0;
		
	}

	left = right = 0;
	
	// From right to left 
	for(int i=str.length()-1; i>0 ;i--)
	{
		if(str[i] == '(')
			left++;
		else
			right++;
			
		if(left == right)
			result = max(result, 2*left);
		else if(left > right)
			left = right = 0;
	}	

	return result;
}


int main()
{
	// string s = ")()(())";
	string s = "(()";
	cout<<longestValidParentheses1(s)<<endl;
	cout<<longestValidParentheses2(s)<<endl;
}