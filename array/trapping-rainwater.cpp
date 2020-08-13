// Level of water filled between the buildings
#include<iostream>
using namespace std;

// TC : O(N)    &    SC : O(N)
int level(int arr[], int size)
{
    int minLeftRight[size];

    // Max from left
    int maxL = arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>maxL)
            maxL = arr[i];
        minLeftRight[i] = maxL;
    }

    // Min(MaxfromLeft & maxFromRight)
    int maxR = arr[size-1];
    for(int i=size-1;i>=0;i--)
    {
        if(arr[i]>maxR)
            maxR = arr[i];
        minLeftRight[i] = min(minLeftRight[i],maxR);
    }

    // Min-arr[i]
    int level=0;
    for(int i=0;i<size;i++)
    {
        level+=(minLeftRight[i]-arr[i]);
    }
    return level;
}


int main()
{
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Level of water trapped : "<<level(arr,size)<<endl;
}