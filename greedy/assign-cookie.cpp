// Assign cookie to each child i to satify his greed with a cookie j of some size.
// Maximize the content of children
#include<iostream>
#include<algorithm> 
using namespace std;

int satisfyChildren(int greed[], int size[], int children, int cookies)
{
    int count=0,j=0;
    sort(greed,greed+children);
    sort(size,size+cookies);
    
    for(int i=0;i<cookies && j<children; i++)
    {
        if(greed[j]<=size[i])
        {
            j++;
            count++;
        }
    }
    return count;
}
int main()
{
    int greed[] = {8,9,7,10};
    int cookie[] = {6,8,7,5};
    int children = sizeof(greed)/sizeof(greed[0]);
    int cookies = sizeof(cookie)/sizeof(cookie[0]);
    cout<<"Max no. of satisfied children : "<<satisfyChildren(greed,cookie,children,cookies)<<endl;
}