#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define size 1000

//Brute force O(N^N)

/*int TotalBTwithN(int n)
{
    if(n==0 || n==1)
        return 1;
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=TotalBTwithN(i)*TotalBTwithN(n-i-1);
    }
    return count;
}*/

//Optimized Technique O(N^2)

int TotalBTwithN(int n , int result[size])
{
    if(n==0)
        result[0];
    if(n==1)
        result[1];
    if(result[n]<0)
    {
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count+=TotalBTwithN(i,result)*TotalBTwithN(n-i-1,result);
        }
        result[n] = count;
    }
    return result[n];
}

int main()
{
    int n;
    cin>>n;

    int result[size];
    memset(result,-1,sizeof(result));
    result[0] = 1;
    result[1] = 1;

    int ans = TotalBTwithN(n,result);
    cout<<ans;
}
