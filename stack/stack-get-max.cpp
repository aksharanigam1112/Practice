// Get max using SC : O(1)
#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class Stack
{
    private:
        stack<int>s;
        int maxSoFar;
    
    public:

        Stack()
        {
            maxSoFar = INT_MIN;
        }

        void insert(int data)
        {
            if(s.empty())
            {
                maxSoFar=data;
                s.push(data);
            }
            else
            {
                if(data>maxSoFar)
                {
                    s.push(2*data+maxSoFar);
                    maxSoFar = data;
                }
                else
                    s.push(data);
            }
        }

        int remove()
        {
            int val = s.top();

            if(val>maxSoFar)
                maxSoFar = val-2*maxSoFar;
            
            s.pop();
            return val;
        }

        int getMax()
        {
            return maxSoFar;
        }
};

int main()
{
    Stack obj = Stack();

    obj.insert(3);
    obj.insert(5);
    obj.insert(2);
    cout<<"Max so far : "<<obj.getMax()<<endl;
    cout<<"Removed element : "<<obj.remove()<<endl;
    cout<<"New Max so far : "<<obj.getMax()<<endl;
    cout<<"Removed element : "<<obj.remove()<<endl;
    cout<<"New Max so far : "<<obj.getMax()<<endl;
    
}
