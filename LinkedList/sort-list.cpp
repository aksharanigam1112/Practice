// Sort a linked list using constant space complexity.
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
ll* sortList1(ll*root)
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

// Merging two sorted lists 
ll* mergeTwoLists(ll* l1, ll* l2) 
{
    if(l1 == NULL)
        return l2;
    
    if(l2 == NULL)
        return l1;
        
    ll* newhead;
        
    if(l1->data <= l2->data)
    {
        newhead = l1;
        newhead->next = mergeTwoLists(l1->next,l2);
    }
    else
    {
        newhead = l2;
        newhead->next = mergeTwoLists(l1,l2->next);
    }
    return newhead;
}
    
// Using MergeSort Technique TC : O(NlogN)

ll* sortList2(ll* head) 
{
    if(head == NULL || head->next == NULL)
		return head;

    ll *slow = head, *fast = head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    ll* head2 = slow->next;
    slow->next = NULL;

    ll* l1 = sortList2(head);
    ll* l2 = sortList2(head2);

    return mergeTwoLists(l1, l2);
}

int main()
{
    ll *root = newNode(-1);
    root->next = newNode(5);
    root->next->next = newNode(3);
    root->next->next->next = newNode(4);
    root->next->next->next->next = newNode(0);

    cout<<"Original List : ";
    print(root);

    ll *sorted = sortList2(root);
    cout<<"Sorted List : ";
    print(sorted);
}