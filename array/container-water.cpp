//  Find two lines, which together with x-axis forms a container, 
// such that the container contains the most water.
#include<iostream>
using namespace std;

// The intuition behind this approach is that the area formed 
// between the lines will always be limited by the height of the shorter line. 
// Further, the farther the lines, the more will be the area obtained.
// TC : O(N)    &   SC : O(1)
int mostWater(int arr[], int size)
{
    int start=0,end=size-1,area=0;
    while(start<end)
    {
        int a = min(arr[start],arr[end]) * (end-start);
        area = max(area,a);
        if(arr[start]<arr[end])
            start++;
        else
            end--;
    }
    return area;
}

int main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Most water contained area : "<<mostWater(arr,size)<<endl;
}