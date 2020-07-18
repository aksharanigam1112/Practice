#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLL
{
    public:
    char data;
    SLL *next;
};

SLL *insert(SLL*head,char data)
{
    SLL*node  = new SLL();
    node->data = data;
    node->next = NULL;
    if(head==NULL)
        head = node;
    else
    {
        node->next = head;
        head = node;
    }
    return head;
}

// Iterative Approach

SLL* reverse(SLL*head)
{
    if(head == NULL || head->next == NULL)
        return head;
    SLL *prev = NULL , *curr = head , *nextpt ;

    while(curr->next !=NULL)
    {
        nextpt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextpt;
    }
    curr->next = prev;
    return curr;
}


//Recursive Approach

SLL* reverseRecur(SLL*head)
{
    if(head==NULL || head->next == NULL )
        return head;
    
    SLL * newhead = reverseRecur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main()
{
    // SLL *head1;
   
    // head1 = insert(head1,'f');
    // head1 = insert(head1,'e');
    // head1 = insert(head1,'d');
    // head1 = insert(head1,'c');
    // head1 = insert(head1,'b');
    // head1 = insert(head1,'a');

    // SLL * rev = reverse(head1);
    // while(rev!=NULL)
    // {
    //     cout<<rev->data<<" ";
    //     rev = rev->next;
    // }

    SLL *head2;

    head2 = insert(head2,'f');
    head2 = insert(head2,'e');
    head2 = insert(head2,'d');
    head2 = insert(head2,'c');
    head2 = insert(head2,'b');
    head2 = insert(head2,'a');

    SLL *newrev = reverseRecur(head2);
    while(newrev!=NULL)
    {
        cout<<newrev->data<<" ";
        newrev = newrev->next;
    }
    cout<<endl;
}