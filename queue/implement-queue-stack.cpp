// Implement queue using stacks
#include<iostream>
#include<stack>
using namespace std;
class Queue
{
    stack<int>q1,q2;
    public:
    void push_data(int data)
    {
        q1.push(data);
    }
    int pop_data()
    {
        while(q1.size()>1)
        {
            q2.push(q1.top());
            q1.pop();
        }
        int d = q1.size()>0 ? q1.top() : 999999 ;
        if(q1.size()>0)
            q1.pop();

        while(!q2.empty())
        {
            q1.push(q2.top());
            q2.pop();
        }
        return d;
    }
};

int main()
{
    Queue q;
    q.push_data(1);
    q.push_data(2);
    cout<<"Popped data : "<<q.pop_data()<<endl;
    q.push_data(3);
    q.push_data(4);
    q.push_data(5);
    cout<<"Popped data : "<<q.pop_data()<<endl;
    cout<<"Popped data : "<<q.pop_data()<<endl;
    cout<<"Popped data : "<<q.pop_data()<<endl;
    cout<<"Popped data : "<<q.pop_data()<<endl;
    cout<<"Popped data : "<<q.pop_data()<<endl;
}
