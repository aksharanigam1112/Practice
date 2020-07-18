#include<iostream>
#include<string> 
using namespace std; 

bool isSubSequence(string r, string g, int m, int n) 
{ 
    int j = 0; 
    for (int i=0; i<m&&j<n; i++) 
	    if (r[i] == g[j]) 
		    j++; 

    return (j==n); 
} 

int main() 
{ 
	int t;
    cin>>t;
    while(t)
    {
        t--;
        string r , g;
        cin>>r>>g;
        int m = r.length();
	    int n = g.length() ;
	    isSubSequence(r, g, m, n)? cout <<"YES"<<endl: cout <<"NO"<<endl; 
    }
	return 0; 
} 
