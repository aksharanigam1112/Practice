// Given an array with both +ive and -ive integers, return a pair with highest product.
#include<iostream>
#include<climits>
using namespace std;
struct Pair
{
    int p1,p2;
};

Pair maxPrd(int arr[], int size)
{
    int maxVal = arr[0], minVal = arr[0], prd=0;
    Pair p ;

    for(int i=1;i<size;i++)
    {
        if(arr[i]<minVal)
        {
            if(arr[i]*minVal>prd)
            {
                p.p1 = minVal;
                p.p2 = arr[i];
                prd = arr[i]*minVal;
            }
            minVal = arr[i];
        }
        if(arr[i]>maxVal)
        {
            if(arr[i]*maxVal>prd)
            {
                p.p1 = maxVal;
                p.p2 = arr[i];
                prd = arr[i]*maxVal;
            }
            maxVal = arr[i];
        }
    }
    return p;
}

int main()
{
    int arr[] = {-1, -3, -4, 2, 0, -5};
    int size = sizeof(arr)/sizeof(arr[0]);
    Pair p = maxPrd(arr,size);
    cout<<"Max Product pair : "<<p.p1<<" "<<p.p2<<endl;
}