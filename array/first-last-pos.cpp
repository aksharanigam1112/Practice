// Given an array of integers nums sorted in ascending order, 
// find the starting and ending position of a given target value.
#include<iostream>
#include<climits>
using namespace std;
struct pos
{
    int first,last;

    pos() : first(INT_MAX), last(INT_MIN) {}
};

pos findPosition(int arr[], int size, int target)
{
    pos p ;
    int low=0,high=size-1,mid=0;
    bool found=false ;

    while(low<=high)
    {
        mid = (high+low)/2;

        if(arr[mid]==target)
        {
            p.first = min(p.first,mid);
            found=true;
            high = mid-1;
        }
        else if(arr[mid]>target)
            high = mid-1;
        else
            low = mid+1;
    }
    if(found==false)
        p.first = -1;
    

    low=0,high=size-1;
    found=false;

    while(low<=high)
    {
        mid = (high+low)/2;

        if(arr[mid]==target)
        {
            p.last = max(p.last,mid);
            found=true;
            low = mid+1;
        }
        else if(arr[mid]>target)
            high = mid-1;
        else
            low = mid+1;
    }
    if(found==false)
        p.last = -1;

    return p;

}
int main()
{
    int arr[] = {2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    pos ans = findPosition(arr,size,2);
    cout<<"First Pos : "<<ans.first<<"\nLast Pos : "<<ans.last<<endl;
}
