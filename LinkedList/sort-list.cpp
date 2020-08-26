// Sort a linked list in O(n log n) time using constant space complexity.
#include<iostream>
using namespace std;
struct ll
{
    int data;
    ll *next;
};

ll* newNode(int data)
{
    ll *n = new ll;
    n->data = data;
    n->next = NULL;
    return n;
}

void print(ll*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


// TC : O(N^2)
ll* sortList(ll*root)
{
    if(root == NULL)
        return NULL;

    ll *newhead = newNode(root->data), *curr;
    root = root->next;
    
    while(root)
    {
        curr = newNode(root->data);
        
        if(newhead->data <= root->data)
        {
            ll  *prev = NULL,*next = newhead;
            while(next && next->data <= root->data)
            {
                prev = next;
                next = next->next;
            }
            prev->next = curr;
            curr->next = next;
        }
        else 
        {
            curr->next = newhead;
            newhead = curr;
        }
        root = root->next;
    }
    return newhead;
}

int main()
{
    ll *root = newNode(-1);
    root->next = newNode(3);
    root->next->next = newNode(3);
    root->next->next->next = newNode(4);
    root->next->next->next->next = newNode(0);

    cout<<"Original List : ";
    print(root);

    ll *sorted = sortList(root);
    cout<<"Sorted List : ";
    print(sorted);
}