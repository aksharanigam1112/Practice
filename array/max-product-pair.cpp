// Given an array with both +ive and -ive integers, return a pair with highest product.
#include<iostream>
#include<climits>
using namespace std;

// 1) Make all pairs TC : O(N^2)

// 2) Sort and then return max(last 2 elements , first 2 elemenst) TC : O(NlogN)

// 3) Find largest & 2nd largest +ve nos , Find smallest & 2nd smallest -ve nos  TC : O(N)
void maxProduct(int arr[], int n)
{
    if(n < 2)
    {
        cout<<"No pairs exist"<<endl;
        return;
    }
 
    if (n == 2)
    {
        cout<<"("<<arr[0]<<","<<arr[1]<<")"<<endl;
        return;
    }
 
    int posa = INT_MIN, posb = INT_MIN , nega = INT_MIN, negb = INT_MIN;
 
    for(int i=0; i<n; i++)
    {
        if (arr[i] > posa)
        {
            posb = posa;
            posa = arr[i];
        }
        else if(arr[i] > posb)
            posb = arr[i];
 
        if(arr[i]<0 && abs(arr[i]) > abs(nega))
        {
            negb = nega;
            nega = arr[i];
        }
        else if(arr[i] < 0 && abs(arr[i]) > abs(negb))
            negb = arr[i];
    }
 
    if (nega*negb > posa*posb)
        cout<<"Max product pair is ("<<nega<<","<<negb<<")"<<endl;
    else
        cout<<"Max product pair is ("<<posa<<","<<posb<<")"<<endl;
}

int main()
{
    int arr[] = {-4,-1,0,-3,2,-5};
    int size = sizeof(arr)/sizeof(arr[0]);
    maxProduct(arr,size);
}