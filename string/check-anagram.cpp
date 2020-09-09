// Check whether two given strings are anagram of each other or not. 
#include<iostream>
using namespace  std;
#define NO_OF_CHARS 256 

bool areAnagram(string str1, string str2) 
{ 
	int count[NO_OF_CHARS] = { 0 }; 
	int i;

	for(i = 0; str1[i] && str2[i]; i++) 
    { 
		count[str1[i]]++; 
		count[str2[i]]--; 
	} 

	if (str1[i] || str2[i]) 
		return false; 

	for(i = 0; i < NO_OF_CHARS; i++)
    { 
		if (count[i]) 
			return false; 
    }
    return true; 
}

int main()
{
    string s1 = "LISTEN", s2= "SILENT";
    cout<<"Are these anagrams : "<<(areAnagram(s1,s2) ? "Yes" : "No")<<endl;
}
