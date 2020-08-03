// Merge k sorted linked lists of different sizes and return it as one sorted list.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct listNode
{
    int data;
    listNode*next;
};

listNode* add(int data)
{
    listNode* n = new listNode;
    n->data = data;
    n->next = NULL;
    return n;
}
struct compare
{
    bool operator()(listNode*a, listNode*b)
    {
        return a->data > b->data;
    }
};

void printList(listNode* head) 
{ 
    while (head != NULL) 
    { 
        cout<<head->data<<" "; 
        head = head->next; 
    }
    cout<<endl; 
} 

// Use K pointers                                            TC : O(N^2 K)
// Create Heap of all Elements                               TC : O(NK LogNK)
// Create Min Heap of 1st element of each list and so on     TC : O(NK LogN)
// Divide & conquer                                          TC : O(NK LogK)

// Using Min heap 
listNode* mergeK1(vector<listNode*>lists)
{
    int k = lists.size();
    listNode *head = NULL, *last;

    priority_queue<listNode*,vector<listNode*>,compare>pq;

    for(int i=0;i<k;i++)
    {
        if(lists[i]!=NULL)
            pq.push(lists[i]);
    }

    while(!pq.empty())
    {
        listNode* top = pq.top();
        pq.pop();

        if(top->next)
            pq.push(top->next);

        if(head==NULL)
        {
            head = top;
            last = top;
        }
        else
        {
            last->next = top;
            last = top;
        }   
    }
    return head;
}

// Using divide & conquer 
listNode* merge2List(listNode* l1, listNode* l2)
{
    listNode *head = new listNode;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    head = l1->data < l2->data ? l1 : l2;
    if(head==l1)
            head->next = merge2List(l1->next , l2);
    else
        head->next = merge2List(l1 , l2->next);
    
    return head;
}


listNode* mergeK2(vector<listNode*>lists)
{
    int k = lists.size();
    vector<listNode*> temp;

    while(lists.size()!=1)
    {
        temp.clear();
        for(int i=0;i<k;i+=2)
        {
            if(i == k-1)
                temp.push_back(lists[i]);
            else
                temp.push_back(merge2List(lists[i],lists[i+1]));
        }
        lists = temp;
    }
    return lists[0];
}

int main()
{
    vector<listNode*>lists;

    listNode *root1 = add(1);
    root1->next = add(4);
    root1->next = add(5);
    lists.push_back(root1);

    listNode *root2 = add(1);
    root2->next = add(3);
    root2->next = add(4);
    lists.push_back(root2);

    listNode *root3 = add(2);
    root3->next = add(6);
    lists.push_back(root3);

    listNode*final = mergeK2(lists);
    cout<<"Merged List : "<<endl;
    printList(final);


}