// You are given a DLL which in addition to the next and previous pointers, 
// it could have a child pointer, which may or may not point to a separate DLL.
// Flatten the list so that all the nodes appear in a single-level horizontally.
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next,*prev,*child;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->next = n->prev = n->child = NULL;
}

void print(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


node* flatten(node *head) 
{ 
	if(head == NULL) 
	    return NULL; 

	node *tmp,*tail = head; 
	while(tail->next != NULL) 
		tail = tail->next; 

	node *cur = head; 
	while (cur != tail) 
	{ 
		if (cur->child) 
		{ 
			tail->next = cur->child; 
            tmp = cur->child; 
			while (tmp->next) 
				tmp = tmp->next; 
			tail = tmp; 
		} 
        cur = cur->next; 
	}
    return head; 
} 

int main()
{
    node*head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);

    node*head2 = newNode(7);
    head2->next = newNode(8);
    head2->next->next = newNode(9);
    head2->next->next->next = newNode(10);

    node* head3 = newNode(11);
    head3->next = newNode(12);

    head1->next->next->child = head2;
    head2->next->child = head3;

    node* head = flatten(head1);
    cout<<"Flattened DLL : ";
    print(head);
}
