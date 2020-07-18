// Search an element in 2D Array
#include<iostream>
#include<vector>
#define M 3
#define N 3
using namespace std;
struct Position
{
    int i=-1,j=-1;
};
// Brute Force TC : O(M*N)

// Binary Search1 TC : O(MLogN)
int binarySearch(int arr[], int size, int target)
{
    int low=0,high=size-1,mid;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

Position findElement(int arr[M][N], int target)
{
    Position p ;
    for(int i=0;i<M;i++)
    {
        if(target>=arr[i][0] && target<=arr[i][N-1])
        {
            int ans = binarySearch(arr[i],N,target);
            if(ans!=-1)
            {
                p.i = i;
                p.j = ans;
                return p;
            }
        }
    }
    return p;
}

// Binary Search2 TC : O(N+M)

int main()
{
    int arr[M][N] = {{1,2,5},{3,8,9},{4,11,15}};
    int target = 4;
    Position p = findElement(arr,target);
    cout<<"Element found at : "<<p.i<<","<<p.j<<endl;
}