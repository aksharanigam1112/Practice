// Given an array of jobs where every job has a deadline 
// and associated profit if the job is finished before the deadline. 
// maximize total profit if only one job can be scheduled at a time.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;
};
bool compare(Job j1, Job j2)
{
    return (j1.profit > j2.profit);
}

void jobSchedule(Job arr[], int size)
{
    sort(arr,arr+size,compare);

    char ans[size+1];
    memset(ans,'x',size+1);
    
    int maxFill=0;
    
    for(int i=0;i<size;i++)
    {
        int d = arr[i].deadline;
        // cout<<"\nDeadline : "<<d;
        for(int j=d;j>=1;j--)
        {
            if(ans[j]=='x')
            {
                // cout<<"\t Assigned at : "<<j<<"th index"<<endl;
                ans[j] = arr[i].id;
                maxFill = max(maxFill,j);
                break;
            }
        }
    }

    for(int i=1;i<=maxFill;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Job arr[] = {{'A',2,100},{'B',1,19},{'C',2,27},{'D',1,25},{'E',3,15}};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Jobs Sequence to be followed : ";
    jobSchedule(arr,size);
}