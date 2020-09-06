#include<iostream>
using namespace std;

// TC : O(N)    &   SC : O(1)
int solve(int arr[], int n)
{
    int i = 0, j = 0, r = 0;
    int len = 2;
    
    if (n < 2)
        return 1;
    
    while (j < n)
    {
        if (i == j && r == 0)
        {
            j++;
            r = (float)arr[j] / (float)arr[j - 1];
            j++;
        }
        else
        {
            float r1 = (float)arr[j] / (float)arr[j - 1];
            if (r1 != r)
            {  
                len = max(len, (j - i));
                i = j - 1;
                j = j - 1;
                r = 0;
            }
            else
                j++;
        }
    }
    if (i != j)
        len = max(len, (j - i));
    return len;
}

int main()
{
    int arr[] = {5,1,25,125,625,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of longest GP : "<<solve(arr,size)<<endl;
}