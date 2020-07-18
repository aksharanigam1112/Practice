#include<iostream>
#include<unordered_set>
using namespace std;
class sll
{
    public:
    int data;
    sll *next;
};

sll*insert(int data)
{
    sll *node = new sll();
    node->data = data;
    node->next = NULL;
    return node;
}

void print(sll*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Brute force uses O(n^2)

// Using Hashing TC:- O(n) SC:- O(n)
void removeDupliactes(sll**head)
{
    unordered_set<int> hash;
    sll*curr = *head;
    sll*prev = NULL;

    while(curr)
    {
        // If found in hash
        if(hash.find(curr->data) != hash.end())
        {
            prev->next = curr->next;
            delete(curr);
        }
        else
        {
            hash.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main()
{
    sll*head;
    head = insert(1);
    head->next = insert(2);
    head->next->next = insert(4);
    head->next->next->next = insert(2);
    head->next->next->next->next = insert(2);
    head->next->next->next->next->next = insert(5);
    head->next->next->next->next->next->next = insert(4);
    cout<<"Original linked list:- \n";
    print(head);
    removeDupliactes(&head);
    cout<<"After removing duplicates:- \n";
    print(head);
}