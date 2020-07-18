// You are given n activities with their start and finish times. 
// Select the maximum number of activities that can be performed
#include<iostream>
#include<algorithm>
using namespace std;
struct Time
{
    int start,finish;
};
bool compare(Time t1, Time t2)
{
    return (t1.finish<t2.finish);
}
void maxActivities(Time time[], int size)
{
    sort(time,time+size,compare);
    int i=0;

    cout<<time[i].start<<","<<time[i].finish<<endl;
    for(int j=1;j<size;j++)
    {
        if(time[j].start>=time[i].finish)
        {
            cout<<time[j].start<<","<<time[j].finish<<endl;
            i=j;
        }
    }
}

int main()
{
    Time time[] = {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};

    int n = sizeof(time)/sizeof(time[0]);
    cout<<"Activities : "<<endl; 
    maxActivities(time,n); 

}