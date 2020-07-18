// Implement queue using 2 stacks
#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    private : 
    stack<int>curr;
    stack<int>del;

    public :
    void insert(int data)
    {
        curr.push(data);
    }

    int remove()
    {
        while(curr.size()!=1)
        {
            del.push(curr.top());
            curr.pop();
        }
        int val = curr.top();
        curr.pop();

        while(!del.empty())
        {
            curr.push(del.top());
            del.pop();
        }
        return val;
    }
}; 

int main()
{
    Queue obj;

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);

    cout<<"Removed Front : "<<obj.remove()<<endl;

    obj.insert(4);
    obj.insert(5);

    cout<<"Removed Front : "<<obj.remove()<<endl;
    cout<<"Removed Front : "<<obj.remove()<<endl;
}