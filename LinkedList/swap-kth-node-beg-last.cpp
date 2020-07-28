// Given a singly linked list, swap kth node from beginning with kth node from end. 
#include<iostream>
using namespace std;
struct node 
{ 
    int data; 
    node* next; 
}; 

node* push(node* head, int data) 
{ 
    node*n = new node;
    n->data = data;
    
    if(head==NULL)    
        n->next = NULL;
    else
        n->next = head;

    head = n;
    return head; 
}

node* kthFromFirstLast(node *head, int n) 
{ 
    if(head==NULL)
        return NULL;

    node *main_ptr = head; 
    node *ref_ptr = head; 

    int count = 1; 
    
    while(count<n && ref_ptr!=NULL) 
    { 
        ref_ptr = ref_ptr->next; 
        count++; 
    }

    node* temp = ref_ptr!=NULL ? ref_ptr : main_ptr;
    ref_ptr = ref_ptr!=NULL ? ref_ptr->next : NULL; 

    while(ref_ptr != NULL) 
    { 
        main_ptr = main_ptr->next; 
        ref_ptr = ref_ptr->next; 
    }

    swap(main_ptr->data,temp->data);
    return head;
}

void print(node* head)
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
    node * head;
    head = push(head,5);
    head = push(head,4);
    head = push(head,3);
    head = push(head,2);
    head = push(head,1);

    cout<<"Initial : ";
    print(head);
    head = kthFromFirstLast(head,4);
    cout<<"After Swapping : ";
    print(head);
}