// Count no of set bits (1)
#include<iostream>
using namespace std;

int setBits(uint32_t n)
{
    int count=0;
    while(n>0)
    {
        int i = n & 1;
        if(i==1)
            count++;
        // Right Shift 
        n = n >> 1;
    }
    return count;
}

int main()
{
    uint32_t n = 256789;
    cout<<"No of set bits : "<<setBits(n)<<endl;
}