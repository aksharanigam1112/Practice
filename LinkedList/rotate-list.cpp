// Given a linked list, rotate the list to the right by k places, where k is non-negative.
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}
void print(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node* rotateList(node*head, int k)
{
    if(head==NULL || head->next==NULL)
        return head;

    int len = 1;
    node* tail = head;
    while(tail->next!=NULL)
    {
        len++;
        tail = tail->next;
    }    
    tail->next = head;

    tail = head;
    for(int i=1;i<len-k%len;i++)
    {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}

int main()
{
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    int k = 2;

    cout<<"Original List : ";
    print(head);

    node* ans = rotateList(head,k);
    cout<<"Rotated List : ";
    print(ans);
}