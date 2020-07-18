// Get max using SC : O(1)
#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class Stack
{
    private:
        stack<int>s;
        int minSoFar;
    
    public:

        Stack()
        {
            minSoFar = INT_MAX;
        }

        void insert(int data)
        {
            if(s.empty())
            {
                minSoFar=data;
                s.push(data);
            }
            else
            {
                if(data<minSoFar)
                {
                    s.push(2*data-minSoFar);
                    minSoFar = data;
                }
                else
                    s.push(data);
            }
        }

        int remove()
        {
            int val = s.top();

            if(val<minSoFar)
                minSoFar = 2*minSoFar-val;
            
            s.pop();
            return val;
        }

        int getMin()
        {
            return minSoFar;
        }
};

int main()
{
    Stack obj = Stack();

    obj.insert(3);
    obj.insert(5);
    obj.insert(2);
    cout<<"Min so far : "<<obj.getMin()<<endl;
    cout<<"Removed element : "<<obj.remove()<<endl;
    cout<<"New Min so far : "<<obj.getMin()<<endl;
    cout<<"Removed element : "<<obj.remove()<<endl;
    cout<<"New Min so far : "<<obj.getMin()<<endl;
    
}
