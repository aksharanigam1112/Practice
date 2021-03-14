#include<iostream>
#include<set>
using namespace std;

int candies(int arr[], int n){

    set<int>hash;
    for(int i=0;i<n;i++)
        hash.insert(arr[i]);

    int count = 0;
    for(auto it : hash){
        if(count<n/2)
            count++;
        else
            break;
    }    
    return count;    
}

int main(){
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Different kinds of candies : "<<candies(arr,n)<<endl;
}