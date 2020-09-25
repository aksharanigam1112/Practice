// Given a number line from -infinity to +infinity. 
// You start at 0 and can go either to the left or right. 
// The condition is that in i’th move, you take i steps.
// a) Find if you can reach a given number x
// b) Find the most optimal way to reach a given number x, if we can indeed reach it
#include<iostream>
#include<climits>
using namespace std;

// Recursion
int steps(int src, int dest, int step)
{
	if(abs(src) > dest)
		return INT_MAX;
	
	if(src == dest)
		return step;

	int right = steps(src+step+1,dest,step+1);
	int left = steps(src-step-1,dest,step+1);

	return min(right,left);
}

// Case 1 : Difference is even then answer is n, 
// (because we will always get a move flipping which will lead to target).
// Case 2 : Difference is odd, then we take one more step, 
// i.e add n+1 to sum and now again take the difference. 
// If difference is even the n+1 is the answer else we would have to take 
// one more move and this will certainly make the difference even then answer will be n+2.

int reachTarget(int dest)
{
	dest = abs(dest);
	int sum=0,step=0;
	while(sum<dest || (sum-dest)%2 !=0)
	{
		step++;
		sum+=step;
	}
	return step;
}

int main()
{
	int dest = 11;

	cout<<"No. of steps req to reach destination : "<<reachTarget(dest)<<endl; 
}