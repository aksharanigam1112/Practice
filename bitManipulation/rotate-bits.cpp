// Input : 111101   Output : 101111
#include<iostream>
using namespace std;

uint32_t rotate(uint32_t n)
{
    uint32_t ans=0, power=31;
    while(n)
    {
        ans += (n & 1) << power;
        n = n >> 1;
        power --;
        
    }
    return ans;
}

int main()
{
    uint32_t n = 18;
    cout<<"Rotated bits : "<<rotate(n)<<endl;
}