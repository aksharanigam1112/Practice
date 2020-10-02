// Sum the ith element of linked list with (n-i-1)th element
// n is the total no. of nodes
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node* next;
};

node* newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

void print(node* head)
{
    while(head)
    {
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<endl;
}

node* sum(node* head)
{
    vector<int>arr;
    node* temp = head;
    while(temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    temp = head;
    int n = arr.size(),i=0;

    while(temp)
    {
        if(i!= (n-i-1))
            temp->data += arr[n-i-1];
        i++;
        temp = temp->next;
    }
    return head;
}

int main()
{
    // Even Length Linked List

    node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(5);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(11);
    head->next->next->next->next->next = newNode(13);

    // Odd Length Linked List 

    // node *head = newNode(1);
    // head->next = newNode(2);
    // head->next->next = newNode(5);
    // head->next->next->next = newNode(11);
    // head->next->next->next->next = newNode(13);

    cout<<"Original Linked List : ";
    print(head);

    node * newHead = sum(head);

    cout<<"Linked List Sum : ";
    print(newHead);
}