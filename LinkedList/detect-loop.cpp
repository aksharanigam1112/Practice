#include<iostream>
using namespace std;
class sll
{
    public:
    int data;
    sll *next;
};

sll* insert(int data)
{
    sll*node = new sll();
    node->data = data;
    node->next = NULL;
}

int findSize(sll*slow , sll*fast)
{
    sll * temp = slow  ;
    int count=1;
    while(temp!=fast)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void cycle(sll ** head)
{
    sll*slow,*fast;
    slow = *head;
    fast = slow->next;
    
    while(slow && fast && slow!=fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow == fast)
    {
        cout<<"Cycle detected "<<endl;

        slow = *head;
        while(slow && fast)
        {
            if(fast->next == slow)
            {
                cout<<"Cycle starts at : "<<slow->data<<" and ends at : "<<fast->data<<" with size : "<<findSize(slow,fast)<<endl;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
    else
        cout<<"Cycle Not Detected "<<endl;
}

int main()
{
    sll*head = insert(1);
    head->next = insert(2);
    head->next->next = insert(3);
    head->next->next->next = insert(4);
    head->next->next->next->next = insert(5);
    head->next->next->next->next->next = insert(6);
    head->next->next->next->next->next->next = head->next->next;

    cycle(&head);

}