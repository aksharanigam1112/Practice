#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int myCompare(string X, string Y) 
{  
	string XY = X.append(Y); 
	string YX = Y.append(X); 

	return XY.compare(YX) >= 0 ? 1: 0; 
} 

void printLargest(vector<string> arr) 
{ 
	sort(arr.begin(), arr.end(), myCompare); 

	for (int i=0; i < arr.size() ; i++ ) 
		cout<<arr[i]; 
} 

int main() 
{ 
	vector<string> arr; 

	arr.push_back("3"); 
	arr.push_back("36"); 
	arr.push_back("43");
    arr.push_back("87");
    arr.push_back("9");
    arr.push_back("462");
    arr.push_back("96");

	printLargest(arr); 
    cout<<endl;

return 0; 
} 
