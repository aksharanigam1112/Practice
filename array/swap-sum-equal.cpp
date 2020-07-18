#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len1 = 3, len2 = 4;
    int arr1[len1]= {8,4,12};
    int arr2[len2] = {2,3,6,9};

    int sum1=0,sum2=0;
    map<int,int>hash;
    for(int i=0;i<len1;i++)
    {
        sum1+=arr1[i];
        hash.insert(make_pair(arr1[i],1));
    }
    for(int i=0;i<len2;i++)
    {
        sum2+=arr2[i];
    }

    if(abs(sum1-sum2)%2!=0)
        cout<<"Not Possible"<<endl;
    else
    {
        int diff = abs(sum1-sum2)/2;
        int flag=0;
        for(int i=0;i<len2;i++)
        {
            if(hash.find(arr2[i]+diff)->first)
            {
                cout<<"Swap:- "<<arr2[i]<<","<<arr2[i]+diff<<endl;
                // flag=1;
                break;
            }
        }
        // if(flag==0)
        //     cout<<"Not Possible"<<;
    }

    return 0;
}