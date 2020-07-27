// Given N gas stations, with the gas provided and cost to travel from i to i+1 th station.
// Find the index position for which the round of all stations is possible.
#include<iostream>
using namespace std;

// TC : O(N^2)
int completeCircuit(int gas[], int cost[], int n)
{
    int start, ans=-1;

    for(start=0;start<n;start++)
    {
        int tank=0,curr;

        if(gas[start]-cost[start] >= 0)
        {
            cout<<"Start : "<<start<<endl;

            tank = gas[start]-cost[start];
            curr = (start+1)%n;
            
            while(tank>=0 && curr!=start)
            {
                cout<<"\n\tTank : "<<tank<<endl;
                tank = tank+gas[curr]-cost[curr];

                curr = (curr+1)%n; 
            }
            cout<<"\n\tTank : "<<tank<<endl;
            if(curr==start && tank>=0)
            {
                ans = start;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int gas[] = {3,3,4};
    int cost[] = {3,4,4};
    int n = sizeof(gas)/sizeof(gas[0]);

    cout<<"Starting station is : "<<completeCircuit(gas,cost,n)<<endl;
}