#include<iostream>
using namespace std;

int colour(int colours , int fences)
{
    if(fences<=0)
        return 0;
    if(fences==1)
        return 1;
    
    return ((colours-1)*colour(colours,fences-2) + (colours-1)*colour(colours,fences-1));
}

int main()
{
    // x = No of colours n = No. of fences
    int x = 2 , n = 5;

    cout<<"\nValid cases :-"<<colour(x,n)<<endl;
}