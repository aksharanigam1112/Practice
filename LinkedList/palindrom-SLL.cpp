#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*next;
};

node* newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

bool isPalindromeUtil(node**left, node* right) 
{ 
    if (right == NULL) 
        return true; 
    
    bool isp = isPalindromeUtil(left, right->next); 

    if (isp == false) 
        return false; 
 
    bool isp1 = (right->data == (*left)->data); 
 
    *left = (*left)->next; 
 
    return isp1; 
} 
 
bool isPalindrome(node* head) 
{ 
    isPalindromeUtil(&head, head); 
} 

int main()
{
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);

    cout<<"Is Palindromic or not ? "<<(isPalindrome(head)?"Yes":"No")<<endl;
}
