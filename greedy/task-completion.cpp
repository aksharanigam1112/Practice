// You are given N sections out of which atleast M have to be done
// Each section has further A,B,C tasks which require some unit time.
// Find the min time required to complete all tasks of M sections
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

int minTime(int arr[][3], int n, int m)
{
    // To store the sum of time req by each section along with its task no.
    // Min heap
    priority_queue<p,vector<p>,greater<p>> pq;

    for(int i=0;i<n;i++)
    {
        int sum = arr[i][0] + arr[i][1] + arr[i][2];
        pq.push({sum,i});
    }

    int tasks[3]={0,0,0};
    
    for(int i=0;i<m;i++)
    {
        int item = pq.top().second;
        tasks[0] = max(arr[item][0],tasks[0]);
        tasks[1] = max(arr[item][1],tasks[1]);
        tasks[2] = max(arr[item][2],tasks[2]);
        pq.pop();
    }
    return tasks[0]+tasks[1]+tasks[2];
}


int main()
{
    int n,m;
    cout<<"Enter total no. of sections : "; 
    cin>>n;

    cout<<"\nEnter min sections to be done : ";
    cin>>m;

    int arr[n][3];

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the time req for each task of this section : ";
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    cout<<"\nMinimum time req to complete m tasks : "<<minTime(arr,n,m)<<endl;
}
