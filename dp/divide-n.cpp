//Divide N in N/2 , N/3 and (N-1) in min steps to reduce to 1
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Brute Force  TC : O(3^N)  
int MinStepsBF(int N)
{
    int R1 = INT_MAX,R2 = INT_MAX,R3 = INT_MAX;

    if(N==1)
        return 0;
    if(N%2==0)
        R2 = MinStepsBF(N/2);

    if(N%3==0)
        R3 = MinStepsBF(N/3);

    R1 = MinStepsBF(N-1);
    return 1+min(R1,min(R2,R3));
}

// Top Down TC : O(3N) & SC : O(N)
int MinStepsTD(int N , int ans[])
{
    if(N==1)
        return 0;

    if(ans[N]<0)
    {   
        int R1 = INT_MAX,R2 = INT_MAX,R3 = INT_MAX; 

        if(N%2==0)
            R2 = MinStepsTD(N/2,ans);

        if(N%3==0)
            R3 = MinStepsTD(N/3,ans);

        R1 = MinStepsTD(N-1,ans);
        ans[N] = 1+min(R1,min(R2,R3));
    }
    return ans[N];
}

// Bottom Up TC : 0(3N) & SC: O(N)
int MinStepsBU(int N, int arr[])
{
    for(int i=4;i<=N;i++)
    {
        int R2 = i%2==0 ? arr[i/2] : INT_MAX;
        int R3 = i%3==0 ? arr[i/3] : INT_MAX;
        int R1 = arr[i-1];
        arr[i] = 1+min(R1,min(R2,R3));
    }
    return arr[N];
}

int main()
{
    int N = 11;
    int ans[N+1],arr[N+1];

    memset(ans,-1,sizeof(ans));
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    cout<<"Brute Force :- "<<MinStepsBF(N)<<endl;
    cout<<"Top Down :- "<<MinStepsTD(N,ans)<<endl;
    cout<<"Bottom Up :- "<<MinStepsBU(N,arr)<<endl;
}