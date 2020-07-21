// Everybody know the celebrity, but the celebrity doesn't know anyone
// Find the celebrity in min no. of checks (whether A knows B or not)
#include<iostream>
#include<bits/stdc++.h>
#define n 4
using namespace std;

// Brute Force TC : O(N^2) & SC : O(1)

// Using stack TC : O(N) & SC : O(N)
int findCeleb1(int arr[n][n])
{
    stack<int>celeb;
    for(int i=0;i<n;i++)
        celeb.push(i);
    
    while(celeb.size()!=1)
    {
        int a = celeb.top();
        celeb.pop();
        int b = celeb.top();
        celeb.pop();

        // if A knows B then A cannot be a celebrity
        if(arr[a][b]==1)
            celeb.push(b);
        // if A doesn't know B then B cannot be a celebrity
        else
            celeb.push(a);
    }

    // Check if the last candidate is a celebrity or not
    int cand = celeb.top();

    for(int i=0;i<n;i++)
    {
        if(i!=cand && (arr[cand][i]==1 || arr[i][cand] == 0))
            return -1;
    }
    return cand;
}

// Using two pointers TC : O(N) & SC : O(1)
int findCeleb2(int arr[n][n])
{
    int A=0, B=n-1;
    while(A<B)
    {
        // if A knows B, the A can't be celebrity
        if(arr[A][B])
            A++;
        // if A doesn't know B, then B can't be a celebrity
        else
            B--;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=A && (arr[A][i]==1 || arr[i][A]==0))
            return -1;
    }
    return A;
}


int main()
{
    int arr[n][n] = {{0,0,1,0},
                    {0,0,1,0},
                    {0,0,0,0},
                    {0,0,1,0}};
    cout<<"The celebrity is : "<<findCeleb2(arr)<<endl;
}