// Given a singly linked list, group all odd nodes together followed by the even nodes. 
#include<iostream>
using namespace std;
struct ll
{
    int data;
    ll*next;
};

ll* newNode(int data)
{
    ll *n = new ll;
    n->data = data;
    n->next = NULL;
    return n;
}

void print(ll*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

ll* oddEven(ll*head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;

    ll* temp = head->next, *even = temp,*newHead=head;
    while(temp!=NULL && temp->next!=NULL) 
    {
        cout<<"head : "<<head->data<<" temp : "<<temp->data<<endl;
        head->next = temp->next;
        head = head->next;
        temp->next = head->next;
        temp = temp->next;
    }
    cout<<"head : "<<head->data<<endl;
    head->next = even;
    return newHead;
}

int main()
{
    ll *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    cout<<"Original list : "<<endl;
    print(head);

    ll* head2 = oddEven(head);
    cout<<"New list : "<<endl;
    print(head2);
}