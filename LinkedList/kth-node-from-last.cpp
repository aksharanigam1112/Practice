#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

int kthFromLast(Node *head, int n) 
{ 
    Node *main_ptr = head; 
    Node *ref_ptr = head; 

    int count = 0; 
    if(head != NULL) 
    { 
        while( count < n ) 
        { 
            if(ref_ptr == NULL) 
                return -1; 

            ref_ptr = ref_ptr->next; 
            count++; 
        } 

        while(ref_ptr != NULL) 
        { 
            main_ptr = main_ptr->next; 
            ref_ptr = ref_ptr->next; 
        } 
        return main_ptr->data; 
    }
    return -1; 
} 

void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node(); 

    new_node->data = new_data; 
    new_node->next = (*head_ref);	 
    (*head_ref) = new_node; 
} 

int main() 
{ 
    Node* head = NULL; 
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 
    // 35->15->4->20
    
    cout<<"Kth node from last : "<<kthFromLast(head, 4)<<endl; 
} 
