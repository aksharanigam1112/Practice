#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
class Node 
{ 
    public:
	char data; 
	Node* next; 
}; 

Node* newNode(char key) 
{ 
	Node* temp = new Node(); 
	temp->data = key; 
	temp->next = NULL; 
	return temp; 
} 

void reverse(Node** head) 
{ 
	Node *prev = NULL, *curr = *head, *next; 

	while (curr) 
    { 
		next = curr->next; 
		curr->next = prev; 
		prev = curr; 
		curr = next; 
	} 

	*head = prev; 
} 

void print(Node* head) 
{ 
	while (head != NULL) 
    { 
		cout << head->data << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 

Node* findMiddle(Node**head)
{
    Node *slow = *head, *fast = slow->next; 
	while (fast && fast->next) 
    { 
		slow = slow->next; 
		fast = fast->next->next; 
	}
    return slow;
}

Node * merge(Node**head , Node*head1 , Node*head2)
{
    *head = newNode('0'); //Dummy value
	
	Node* curr = *head; 
    while (head1 || head2) 
    { 
		if (head1) 
        { 
			curr->next = head1; 
			curr = curr->next; 
			head1 = head1->next; 
		} 
		if (head2) 
        { 
			curr->next = head2; 
			curr = curr->next; 
			head2 = head2->next; 
		} 
	}
    return *head;
}

void rearrange(Node** head) 
{ 
    //finding middle element 
	Node* head1 = *head; 
	Node* mid = findMiddle(head);
    Node* head2 = mid->next; 
	mid->next = NULL; 

	reverse(&head2); 
	
	*head =  merge(head,head1,head2);
	*head = (*head)->next; 
} 

int main() 
{ 
	Node* head = newNode('a'); 
	head->next = newNode('b'); 
	head->next->next = newNode('c'); 
	head->next->next->next = newNode('d'); 
	head->next->next->next->next = newNode('e'); 

    cout<<"Original list :- "<<endl;
	print(head);
	rearrange(&head); 
    cout<<"Rearranged list :- "<<endl;
	print(head); 
	return 0; 
} 
