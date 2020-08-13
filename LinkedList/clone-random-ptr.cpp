// Clone the linked list with random pointers and return  the list
#include<iostream>
using namespace std;
struct ll
{
    int data;
    ll*next,*random;
};

ll* newNode(int data)
{
    ll* n = new ll;
    n->data = data;
    n->next = n->random = NULL;
    return n;
}
// Using hash map to store which ndex position is linked to which pointers
// TC : O(N)    &   SC : O(N)

// Using pointers 
// TC : O(N)    &   SC : O(1)
ll* clone(ll *head) 
{ 
    ll* curr = head; 

    // Placing the nodes in between 
    while(curr)
    {
        ll *temp = newNode(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }

    curr = head; 
    ll* copied = curr->next;

    // Copying the random pointers
    while(curr)
    {
        copied->random = curr->random->next;
        curr = copied->next;
        copied = copied->next ? copied->next->next : NULL; 
    } 

    ll* original = head;

    copied = head->next; 
    curr = copied; 
  
    // Separating the original list and copied list 
    while (original && copied) 
    { 
        original->next = original->next ? original->next->next : NULL; 
        copied->next = copied->next ? copied->next->next : NULL; 
        original = original->next; 
        copied = copied->next; 
    } 
    return curr; 
} 

void print(ll* head)
{
    while(head)
    {
        cout<<head->data<<" ---> "<<head->random->data<<endl;
        head = head->next;
    }
}

int main()
{
    ll *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);

    head->random = head->next->next;        // 1----> 3
    head->next->random = head->next->next->next->next; // 2---->5
    head->next->next->random = head->next->next->next->next->next;  // 3---->6
    head->next->next->next->random = head->next;    // 4---->2
    head->next->next->next->next->random = head;    // 5---->1
    head->next->next->next->next->next->random = head->next;    // 6---->2

    cout<<"Original list : "<<endl;
    print(head);

    cout<<"Copied List : "<<endl;
    ll* copied = clone(head);
    print(copied);
}