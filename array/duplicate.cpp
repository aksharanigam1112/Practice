// Finding duplicate in an unsorted array of size n containing n-1 elements with atleast one duplicate

#include<iostream>
#include<set>
using namespace std;

// Brute Force O(n^2)

//Sorting & then check O(logn + n) 

// Hashing using Map / Set  TC:- O(n) & SC:- O(n) 
int hashing(int arr[] , int n)
{
    set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]) != s.end())
            return arr[i];
        else
            s.insert(arr[i]);
    }
}


// Floyd's Cycle Detection TC:- O(n) & SC:- O(1)
int floyd(int *arr)
{
    int slow = arr[0];
    int fast = arr[arr[0]];

    while(slow!=fast)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

    fast = 0;
    while(slow!=fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main()
{
    int arr[] = {1,4,3,5,6,1,2};
    // int arr[] = {1,2,3,4,5,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Using Floyd's cycle : "<<floyd(arr)<<endl;


    cout<<"Using hashing : "<<hashing(arr , size)<<endl;
}