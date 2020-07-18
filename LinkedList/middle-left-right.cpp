#include<iostream>
using namespace std;
class Node
{
    public:
    char data;
    Node*next;
};

Node * insert(char data)
{
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void print(Node*head)
{
    Node*temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
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

Node* merge(Node**head , Node*head1 , Node*head2)
{
    *head = insert('0');
    Node*curr = *head ;

    curr->next = head1;
    head1 = head1->next;
    curr = curr->next;

    while(head1 || head2)
    {
        if(head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if(head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    return (*head)->next;
}

int main()
{
    Node* head ;
    head = insert('a');
    head->next = insert('b');
    head->next->next = insert('c');
    head->next->next->next = insert('d');
    head->next->next->next->next = insert('e');

    print(head);

    Node * mid = findMiddle(&head);
    Node*head1 = head;
    Node*head2 = mid->next;
    mid->next = NULL;

    reverse(&head1);
    
    Node * newList = merge(&head , head1 , head2);
    print(newList);
    return 0;
}