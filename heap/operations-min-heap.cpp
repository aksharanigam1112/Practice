#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printHeap(vector<int>arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


class heap
{
    public : 
        vector<int>arr; 
         int size;

    heap()
    {
        arr = {10,15,21,25,18,30,40,49,26,19};
        size = arr.size();
    }

    void percolateUp(int i)
    {
        if(i==0)
            return ;

        int parent = i%2==0 ? i/2-1 : i/2;
        if(arr[i] < arr[parent])
        {
            swap(arr[i],arr[parent]);
            percolateUp(parent);
        }
    }

    void heapify(int index)
    {
        if(index>=size)
            return;

        if(2*index+1>=size)
            return;

        int min = 2*index+2 > size ? 2*index+1 : (arr[2*index+2]<arr[2*index+1] ? 2*index+2 : 2*index+1);
        
        if(arr[min]<arr[index])
        {
            swap(arr[min],arr[index]);
            heapify(min);
        }
    }

    void add(int val)
    {
        arr.push_back(val);
        cout<<"Adding the value at the end :"<<endl;
        printHeap(arr);
        percolateUp(size-1);
    }

    int removeTop()
    {
        if(size-1==0)
            return INT_MAX;
        int val = arr[0];
        swap(arr[0],arr[size-1]);
        this->size--;
        this->heapify(0);
        return val;
    }
};


int main()
{
    heap obj = heap();
    
    obj.add(12);
    cout<<"Minimum element is : "<<obj.removeTop()<<endl;
    cout<<"Next Minimum element is : "<<obj.removeTop()<<endl;
}