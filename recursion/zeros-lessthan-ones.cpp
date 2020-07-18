#include <iostream>
#include <string>
using namespace std;

void solution(string currentNumber, int extraOnes, int remainingPlaces)
{
	if (remainingPlaces == 0)
	{
		cout <<currentNumber<<endl;
		return;
	}
	solution(currentNumber+"1", extraOnes+1, remainingPlaces-1);
	if (extraOnes>0)
	    solution(currentNumber+"0", extraOnes-1, remainingPlaces-1);
}

int main()
{
	int numberOfDigits = 4;
	string str;
	solution(str, 0, numberOfDigits);
	return 0;
}