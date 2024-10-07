#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data){
    Node *n = new Node;
    n->data = data;
    n->next = NULL;
    return n;
}

void print(Node* head) {
    
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Recursive TC : O(N) & SC : O(N)
Node* reverseRecur(Node* head) {

    if(head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverseRecur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Iterative TC : O(N) & SC : O(1)
Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* prev = NULL;

    while(head != NULL) {
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    
    return prev;
}


Node* reverseBetween(Node* head, int left, int right) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* prev = NULL, *temp1 = head, *temp2 = head;
    
    int l = 1;
    while(l < left) {
        prev = temp1;
        temp1 = temp1->next;
        l++;
    }

    int r = 1;
    while(r < right) {
        temp2 = temp2->next;
        r++;
    }

    Node* last = NULL;
    if(temp2->next != NULL) {
        last = temp2->next;
        temp2->next = NULL; 
    }

    if(prev != NULL) {
        prev->next = reverse(temp1);
    } else {
        head = reverse(temp1);
    }

    temp1->next = last; 
    return head;
    
}


int main() {
    Node* ll = newNode(10);
    ll->next = newNode(20);
    ll->next->next = newNode(30);
    ll->next->next->next = newNode(40);
    ll->next->next->next->next = newNode(50);

    // cout<<"Reverse linked list using recursion : ";
    // Node* newhead1 = reverseRecur(ll);
    // print(newhead1);

    // cout<<"Reverse linked list using iteration : ";
    // Node* newhead2 = reverse(ll);
    // print(newhead2);

    int left = 2, right = 4;
    cout<<"Reverse linked list between nodes "<<left<<" to "<<right<<" : ";
    Node* newhead3 = reverseBetween(ll, left, right);
    print(newhead3);
}
