// Given nos from 1-N, find the no. of different BST's possible
// Hint :- Catlan No. F(N) = Summation(i=1,N) {F(i-1) * F(N-i)}
#include<iostream>
using namespace std;
// Brute Force TC : O(2^N)

// Bottom Up TC : O(N^2)
int numTrees(int n) 
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
        
    for(int i=2;i<=n;i++)
    {
        int total=0;

        for(int j=1;j<=i;j++)
        {
            total+=dp[j-1]*dp[i-j];
        }
        dp[i] = total;
    }
    return dp[n];
}

int main()
{
    int num = 3;
    cout<<"No. of Different BST's possible : "<<numTrees(num)<<endl;
}