/* Reference : https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/

Input : Head of following linked list  
       1->2->3->4->5->6->7->8->9->10->11->NULL

Delete n nodes number after m positions

For eg : n = 2 & m = 3
Output : Linked list should be changed to,
       1->2->3->6->7->8->11->NULL
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int d){
    Node* n = new Node;
    n->data = d;
    n->next = NULL;
    return n;
}

void print(Node* head){
    if(head == NULL)
        return;

    while(head->next != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }

    cout<<head->data<<endl;
        
}

Node* deleteNNodeAfterMPostion(Node* head, int N, int M) {
    if(head == NULL || N < 0 || M < 0)
        return NULL;

    if(M==0){
        free(head);
        return NULL;
    }

    if(N == 0)
        return head;
    
    Node* curr = head, *prev = NULL, *prevDelete = NULL, *newHead = NULL;
    int i=0, j=0;
    
    while(curr != NULL && i < M){
        prev = curr;
        curr = curr->next;
        i++;
    }


    while(curr != NULL && j < N) {
        prevDelete = curr;
        curr = curr->next;
        
        prevDelete->next = NULL;
        delete(prevDelete);
        j++;
    }

    if(curr != NULL)
        newHead = deleteNNodeAfterMPostion(curr, N, M);
     
    if(prev != NULL)
        prev->next = newHead;

    return head;                 
}


int main(){
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next->next->next = newNode(9);
    head->next->next->next->next->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next->next->next->next->next = newNode(11);
    
    cout<<"Original linked list : "<<endl;
    print(head);    

    
    Node* newHead = deleteNNodeAfterMPostion(head, 2, 3);
    // Node* newHead = deleteNNodeAfterMPostion(head, 1, 0);
    // Node * newHead = deleteNNodeAfterMPostion(head, 1, -1);

    cout<<"\nNew linked list : "<<endl;
    print(newHead);    
}
