#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLL
{
    public:
    char data;
    SLL *next;
};

SLL *insert(SLL*head,char data)
{
    SLL*node  = new SLL();
    node->data = data;
    node->next = NULL;
    if(head==NULL)
        head = node;
    else
    {
        node->next = head;
        head = node;
    }
    return head;
}

SLL *reverse(SLL *head, int k)  
{  
    SLL *current = head,*next = NULL, *prev = NULL;  
    int count = 0;  
      
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    if (next != NULL)                          
        head->next = reverse(next, k);  
  
    return prev;  
}  


int main()
{
    SLL *head,*temp;
   
    head = insert(head,'g');
    head = insert(head,'f');
    head = insert(head,'e');
    head = insert(head,'d');
    head = insert(head,'c');
    head = insert(head,'b');
    head = insert(head,'a');
    
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    SLL * rev = reverse(head,4);
    while(rev!=NULL)
    {
        cout<<rev->data<<" ";
        rev = rev->next;
    }
    cout<<endl;
}