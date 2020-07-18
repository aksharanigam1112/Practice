#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLL
{
    public:
    char data;
    SLL *next;
};

SLL * insert(SLL*head,char data)
{
    SLL*node = new SLL();
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

SLL * reversePairwise(SLL *head)
{
    if(head == NULL || head->next == NULL )
        return head;
        
    SLL *newHead = new SLL();
    newHead = head->next;
    head->next = reversePairwise(newHead->next);
    newHead->next = head;
    return newHead;
}

int main()
{
    SLL *head ;
    // head = insert(head ,'g');
    head = insert(head ,'f');
    head = insert(head ,'e');
    head = insert(head ,'d');
    head = insert(head ,'c');
    head = insert(head ,'b');
    head = insert(head ,'a');

    SLL * ans = reversePairwise(head);

    while(ans!=NULL)
    {
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}