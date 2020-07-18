// Cut the rod of length N in such a way that it maximizes the profit

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force TC : O(length ^ N)

int MaxProfitBF(int prices[][6],int length , int N)
{
    if(N==0)
        return 0;
    if(N<0)
        return INT_MIN;

    int max_prof=0;
    for(int i=0;i<length;i++)
    {
        max_prof = max(prices[1][i]+MaxProfitBF(prices,length,N-prices[0][i]), max_prof);
    }
    return max_prof;
}

// Bottom Up
// int MaxProfitBU(int prices[][6] , int length , int N , int ans[])
// {
//     for(int i=1;i<=N;i++)
//     {
//         int maxProf=0,val=prices[1][i-1];
//         cout<<"\nFor "<<i<<endl;
//         for(int j=0 ; prices[0][j]<i ; j++)
//         {
//             val = prices[1][j] + ans[i-prices[0][j]] ; 
//             // maxProf = max(maxProf , prices[1][j] + ans[i-prices[0][j]]);
//             cout<<"\t"<<prices[0][j]<<" "<<val<<endl;
//         }
//         maxProf = max(maxProf , max(val,find(prices,i));
//         ans[i] = maxProf;
//         cout<<"\t\t"<<ans[i]<<endl;
//     }
//     return ans[N];
// }

int main()
{
    int prices[2][6]={{1,2,5,7,10,15},
                    {1,3,12,18,21,33}};

    int N=30,length=6;
    int arr[N+1];
    arr[0] = 0;
    // arr[1] = prices[0][1];

    cout<<"Brute Force :- "<<MaxProfitBF(prices,length,N)<<endl;
    // cout<<"Bottom Up :- "<<MaxProfitBU(prices,length,N,arr)<<endl;

}