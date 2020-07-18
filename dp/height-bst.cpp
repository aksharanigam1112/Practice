// For a gievn height find the no. of possible balanced bst's 
#include<iostream>
#include<math.h>
using namespace std;

//Brute Force Original TC : O(6^N) and redced to TC : O(2^N) SC : O(N)
int bstBF(int height)
{
    if(height==0 || height==1)
        return 1;
    int f1 = bstBF(height-1);
    int f2 = bstBF(height-2);

    return (f1*f1 + 2*f1*f2); 
}

// Top down TC : O(N)
int bstTD(int height)
{
    int dp[height+1];
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=height;i++)
    {
        dp[i] = pow(dp[i-1],2) + 2*dp[i-1]*dp[i-2];
    }
    return dp[height];
}

int main()
{
    int height = 4;
    cout<<"No. of bst's possible are BF :- "<<bstBF(height)<<endl;
    cout<<"No. of bst's possible are TD :- "<<bstTD(height)<<endl;
}