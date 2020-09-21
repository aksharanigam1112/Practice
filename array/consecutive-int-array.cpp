// Check if the array is formed by consecutive integers
#include<iostream>
#include<set>
#include<climits>
using namespace std;

bool checkArray(int arr[], int size)
{
    set<int>hash;
    int  min_ele  = INT_MAX, max_ele = INT_MIN;

    for(int i=0;i<size;i++)
    {
        if(hash.find(arr[i]) != hash.end())
            return false;
        
        min_ele = min(min_ele,arr[i]);
        max_ele = max(max_ele,arr[i]);
        hash.insert(arr[i]);
    }

    while(max_ele>min_ele)
    {
        if(hash.find(max_ele-1) != hash.end())
            max_ele--;
        else
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {-1,5,4,2,0,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Is array formed of consecutive nos : "<<(checkArray(arr,size) ? "Yes" : "No")<<endl;
}