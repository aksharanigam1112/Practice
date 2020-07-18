#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len1 = 5, len2 = 4,r1=0,r2=0;
    int arr1[len1]= {8,15,21,45,60};
    int arr2[len2] = {5,12,15,24};

    int diff = INT_MAX;
    pair<int,int>pair;

    while(r1<len1 && r2<len2)
    {
        if(abs(arr1[r1] - arr2[r2]) < diff)
        {
            diff = abs(arr1[r1] - arr2[r2]);
            pair.first = arr1[r1];
            pair.second = arr2[r2];
        }
        if(arr1[r1] < arr2[r2])
            r2++;
        else
            r1++;
    }
    cout<<"Min diff :-"<<diff<<" ("<<pair.first<<","<<pair.second<<")"<<endl;
    return 0;  
}