// Implement stack using queues
#include<iostream>
#include<queue>
using namespace std;
class Stack
{
    queue<int>st1,st2;
    
    public :
    void push_data(int data)
    {
        st1.push(data);
        // cout<<"Front/Last data : "<<st1.front();
        // cout<<"\t\tBack/Top data : "<<st1.back()<<endl;
    }

    int pop_data()
    {
        int d;
        while(st1.size()>1)
        {
            st2.push(st1.front());
            st1.pop();
        }
        d = st1.front();
        st1.pop();

        swap(st1,st2);
        return d;
    }
};

int main()
{
    Stack s;
    s.push_data(1);
    s.push_data(2);
    cout<<"Popped data : "<<s.pop_data()<<endl;
    s.push_data(3);
    s.push_data(4);
    s.push_data(5);
    cout<<"Popped data : "<<s.pop_data()<<endl;
}