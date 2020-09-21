// Given an unsorted array containing duplicates, rearrange the given array
// same element appears together & relative order of the first occurence of the elements
// remains unchanged. For eg : {1,3,2,1,2} ==> {1,1,3,2,2}
#include<iostream>
#include<map>
using namespace std;

void group(int arr[], int size)
{
    map<int,int>hash;
    for(int i=0;i<size;i++)
        hash[arr[i]]++;
    
    for(int i=0;i<size;i++)
    {
        if(hash.find(arr[i]) != hash.end())
        {
            int freq = hash[arr[i]];
            while(freq--)
                cout<<arr[i]<<" ,";
            hash.erase(arr[i]);
        }
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1,3,2,1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Grouped elements : ";
    group(arr,size);
}