// Given two integers TomatoSlices and CheeseSlices.
// Jumbo Burger ==> 4 TomatoSlices, 1 CheeseSlice
// Small Burger ==> 2 TomatoSlices, 1 CheeseSlice
// Find the possible combination such that 0 slices of both tomato & cheese are left.
#include<iostream>
#define MIN -999
using namespace std;
struct count
{
    int jumbo=0,small=0;
    bool possible=false;
};

// Recursive Top Down DP
count countSlices(int t, int c)
{
    count ans;
    
    if(t==0 && c==0)
    {
        ans.possible = true;
        return ans;
    }

    if(t<0 || (t==0 && c>0)) 
    {
        ans.jumbo = MIN;
        ans.small = MIN;
        ans.possible = false;
        return ans;
    }
    
    // Jumbo
    count LV = countSlices(t-4,c-1);
    // Small
    count RV = countSlices(t-2,c-1);
    
    if(LV.possible)
    {
        ans.jumbo = 1+LV.jumbo;
        ans.possible = true;
    }
    if(RV.possible)
    {
        ans.small = 1+RV.small;
        ans.possible = true;
    }
    return ans;
} 

int main()
{   
    count ans = countSlices(16,7);
    cout<<"Jumbo Burgers : "<<ans.jumbo<<" , Small Burgers : "<<ans.small<<endl;
}