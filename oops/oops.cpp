#include<iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"Const of A called"<<endl;
    }
    void display()
    {
        cout<<"In class A"<<endl;
    }
    ~A()
    {
        cout<<"Dest of A called"<<endl;
    }
};

class B : public A
{
    public:
    B()
    {
        cout<<"Const of B called"<<endl;
    }
    void display()
    {
        cout<<"In class B"<<endl;
    }
    ~B()
    {
        cout<<"Dest of B called"<<endl;
    }
};

class C :  public B // ,public A
{
    public:
    C()
    {
        cout<<"Const of C called"<<endl;
    }
    void display()
    {
        cout<<"In class C"<<endl;
    }
    ~C()
    {
        cout<<"Dest of C called"<<endl;
    }
};

int main()
{

    // // Copy constructor (Parent class mein hi child class ka const store ho sakta hai)
    // //(Kyonki B ka const call hoke khatam ho jaa raha as uska assignment A) 
    // // (mein ho raha isliye dest bhi call ho rahe)
    // A obj1 = B();
    // obj1.display();
    
    // // Creating obj of B type is not allowed
    // B obj = A();

    // // Creating obj of B
    // B obj2;
    // obj2.display();

    // // Creating obj for multiple inheritance
    C obj3;
    obj3.display();

}