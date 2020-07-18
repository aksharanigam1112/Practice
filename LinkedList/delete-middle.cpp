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

void deleteMiddle(sll**head)
{
    sll*slow = *head , *fast = (*head)->next , *prev = NULL;

    while(slow && fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle element :- "<<slow->data<<endl;
    prev->next = slow->next;
    delete(slow);
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

int main()
{
    sll*head = insert(1);
    head->next = insert(2);
    head->next->next = insert(3);
    head->next->next->next = insert(4);
    // head->next->next->next->next = insert(5);
    print(head);
    deleteMiddle(&head);
    print(head);
}