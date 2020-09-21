// The ith person has weight people[i], and each boat can carry a maximum weight of limit.
// Each boat carries at most 2 people at the same time, 
// provided the sum of the weight of those people is at most limit.
// Return the min no of boats to carry every given person.  
#include<iostream>
#include<algorithm>
using namespace std;

// Using 2 pointer concept as atmost 2 people can be carried
// TC : O(NlogN)
int minBoats(int arr[], int size, int limit)
{
    sort(arr,arr+size);
    int i = 0, j = size-1, count=0;

    while(i<=j)
    {
        if(arr[i] + arr[j] <= limit)
            i++;
            
        j--;
        count++;
    }
    return count;
}

int main()
{
    int arr[] = {3,2,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min no. of boats needed : "<<minBoats(arr,size,3)<<endl;
}