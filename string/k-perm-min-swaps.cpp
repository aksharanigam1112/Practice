#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string nextPrem(string str)
{
    for(int i=str.length()-1;i>0;i--)
    {
        if(str[i] > str[i-1])
        {
            int j = str.length()-1;
            
            while(str[j] <= str[i-1])
                j--;
            
            swap(str[j],str[i-1]);
            sort(str.begin()+i, str.end());
            break;  
        }
    }
    return str;
}

int getMinSwaps(string num, int k) 
{
    string ans = num;
    int h = k , count=0;

    while(k--)
    {
        ans = nextPrem(ans);
        cout<<h-k<<"th perm : "<<ans<<endl;
    }

    for(int i = num.size()-1; i >= 0; i--) 
    {
        int j = i;
        while(ans[j] != num[i])
            j--;
        
        for(int k=j; k<i; k++) 
        {
            swap(ans[k], ans[k+1]);
            count++;
        }
    }
    return count;   
}


int main()
{
    string s = "11112";
    cout<<"Kth permutation : "<<getMinSwaps(s,4)<<endl;
    
}