// Compute and return the square root of A.
// If A is not a perfect square, return floor(sqrt(A)).
#include<iostream>
#include<math.h>
using namespace std;

int squareRoot(int target)
{
    if(target == 0 || target == 1)  
       return target; 
  
    int start = 1, end = target, ans, mid;    
    while (start <= end)  
    {         
        mid=(start+end)/2; 
  
        if (mid*mid == target) 
            return mid; 
  
        if (mid*mid<target)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else  
            end = mid-1;         
    } 
    return ans; 
}


int main()
{
    int target = 8;
    cout<<"Square root : "<<squareRoot(target)<<endl;
}