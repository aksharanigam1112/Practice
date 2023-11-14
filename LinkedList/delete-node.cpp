#include<iostream>
using namespace std;

class sll{
    public:
    int data;
    sll*next;
};

sll* insert(int data){

    sll*node = new sll();
    node->data = data;
    node->next = NULL;
    return node;
}

void deleteMiddle(sll**head)
{
    sll*slow = *head , *fast = (*head)->next , *prev = NULL;

    while(slow && fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout<<"Middle element : "<<slow->data<<endl;
    prev->next = slow->next;
    delete(slow);
}

void print(sll*head)
{
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

// Remove Nth Node from the end & return new head
sll* removeNthNode(sll* head, int n) {

    sll* temp = head, *prev = NULL;

    int totalNodes = 0;
    while(temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }

    temp = head;
    int count = totalNodes - n;

    if(count < 0)
        return head;

    while(temp != NULL && count > 0) {
        prev = temp;
        temp = temp->next;
        count--;
    }

    
    sll* next = temp->next;
    
    if(prev != NULL) 
        prev->next = next;
    else
        head = next;

    temp->next = NULL;
    delete(temp);
    
    return head;
}

int main()
{
    sll*head = insert(1);
    head->next = insert(2);
    head->next->next = insert(3);
    head->next->next->next = insert(4);
    head->next->next->next->next = insert(5);
    head->next->next->next->next->next = insert(6);

    cout<<"Actual linked list : ";
    print(head);

    deleteMiddle(&head);
    cout<<"Deleting middle element : ";
    print(head);

    int n = 4;
    sll* ans = removeNthNode(head, n);
    cout<<"After removing "<<n<<"th node from the end : ";
    print(ans);
}
