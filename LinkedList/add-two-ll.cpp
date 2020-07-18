#include<iostream>
using namespace std;
class sll
{
    public:
    int data;
    sll*next;
};

sll*insert(int data)
{
    sll*node = new sll();
    node->data = data;
    node->next = NULL;
    return node;
}

void print(sll*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

sll* reverseRecur(sll*head)
{
    if(head==NULL || head->next == NULL )
        return head;
    
    sll * newhead = reverseRecur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

sll *newnode(sll*head,int data)
{
    sll*node  = new sll();
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


sll * sum(sll**head1 , sll**head2)
{
    sll * newList;
    sll* h1 = *head1 , *h2 = *head2;
    while(h1!=NULL ||  h2!=NULL)
    {
        int sum=0;
        if(h1!=NULL)
        {
            sum+=h1->data;
            // cout<<h1->data<<" ";
            h1 = h1->next;
        }
        if(h2!=NULL)
        {
            sum+=h2->data;
            // cout<<h2->data<<" ";
            h2 = h2->next;
        }
        
        newList = newnode(newList , sum%10);
        int r = sum/10;
        if(h1)
            h1->data+=r;
        else if(h2)
            h2->data+=r;
    }
    return newList;
}

int main()
{
    sll*head1 = insert(2);
    head1->next = insert(3);
    // head1->next->next = insert(1);

    sll*head2 = insert(1);
    head2->next = insert(4);
    
    // print(head1);
    // print(head2);

    sll* newhead1 = reverseRecur(head1);
    sll* newhead2 = reverseRecur(head2);

    sll * added = sum(&newhead1 , &newhead2);
    print(added);

}