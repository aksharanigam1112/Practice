// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect else return null
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node * newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->next=NULL;
    return n;
}

// 2-Pointer technique
node* yList(node* head1, node* head2){

    if(head1 == NULL || head2 == NULL)
        return NULL;  

    node *ptr1 = head1, *ptr2 = head2;

    while(ptr1 != ptr2){
        if(ptr1 == NULL)
            ptr1 = head2;
        if(ptr2 == NULL)
            ptr2 = head1;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}

int main(){

    node *head1 = newNode(4);
    head1->next = newNode(1);
    head1->next->next = newNode(8);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);

    node* head2 = newNode(5);
    head2->next = newNode(6);
    head2->next->next = newNode(1);
    head2->next->next->next = head1->next->next;

    cout<<"Intersection Node is : "<<(yList(head1,head2))->data<<endl;

}