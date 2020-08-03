#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLL
{
    public:
    int data ;
    SLL*next ;
};


SLL * mergeSorted(SLL *head1 , SLL *head2)
{
    SLL *head = new SLL();
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    head = head1->data < head2->data ? head1 : head2;
    if(head==head1)
        head->next = mergeSorted(head1->next , head2);
    else
        head->next = mergeSorted(head1 , head2->next);
    
    return head;
}

SLL * insert(SLL *head , int data)
{
    SLL *node = new SLL();
    node->data = data;
    node->next = NULL;

    if(head == NULL)
        head = node;
    else
    {
        node->next = head;
        head = node;
    }
    return head;
    
}

int main()
{ 
    SLL *l1 = new SLL() ;
    SLL *l2 = new SLL();
    
    l1 = insert(l1,105);
    l1 = insert(l1,45);
    l1 = insert(l1,25);
    l1 = insert(l1,15);
    l1 = insert(l1,10);

    l2 = insert(l2,52);
    l2 = insert(l2,48);
    l2 = insert(l2,21);
    l2 = insert(l2,17);

    SLL *ans = mergeSorted(l1 , l2);

    while(ans->next!= NULL)
    {
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}