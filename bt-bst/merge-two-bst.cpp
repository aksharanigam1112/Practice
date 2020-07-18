#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left,*right;
};

class INOP
{
    public :
    node*prev,*head;

    INOP()
    {
        prev = NULL;
        head = NULL;
    }

    void BSTtoDLL(node*root)
    {
        if(root==NULL)
            return;

        BSTtoDLL(root->left);

        if(this->prev == NULL)   
            this->head = root;
        else
        {
            root->left = this->prev;
            this->prev->right = root;
        }
        this->prev = root;
        BSTtoDLL(root->right);
    }
};

void printList(node *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->right; 
    }
    cout<<endl; 
}

node* mergeSortedDLL(node *first, node *second)  
{    
    if (first == NULL)  
        return second;  
    
    if (second == NULL)  
        return first;  
    
    if (first->data < second->data)  
    {  
        first->right = mergeSortedDLL(first->right,second);  
        first->right->left = first;  
        first->left = NULL;  
        return first;  
    }  
    else
    {  
        second->right = mergeSortedDLL(first,second->right);  
        second->right->left = second;  
        second->left = NULL;  
        return second;  
    }  
}

node* DLLtoBST(node **head, int count)  
{  
    if (count<=0)  
        return NULL;  
    
    node *left = DLLtoBST(head, count/2);  
    
    node *root = *head;  
    
    root->left = left;  
    
    *head = (*head)->right;  
    
    root->right = DLLtoBST(head, count-count/2-1);  
    return root;  
}

node* newNode(int val)
{
    node * ele = new node;
    ele->data = val;
    ele->left = ele->right = NULL;
    return ele;
}

void levelOrder(node*root)
{
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        struct node*ele = q.front();

        if(ele!=NULL)
            cout<<ele->data<<" ";
        if(ele == NULL)
            cout<<endl;
            
        q.pop();

        if(ele!=NULL)
        {
            if(ele->left!=NULL)
                q.push(ele->left);
            if(ele->right!=NULL)
                q.push(ele->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
        }
    }
}

int main()
{
    node* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(10);
    root1->right->left = newNode(7);
    root1->right->right = newNode(15);

    node*root2 = newNode(14);
    root2->left = newNode(5);
    root2->right = newNode(20);
    root2->right->left = newNode(19);
    root2->right->right = newNode(22);

    INOP obj1 = INOP();
    obj1.BSTtoDLL(root1);
    printList(obj1.head);

    INOP obj2 = INOP();    
    obj2.BSTtoDLL(root2);
    printList(obj2.head);

    INOP obj3 = INOP();
    obj3.head = mergeSortedDLL(obj1.head,obj2.head);
    printList(obj3.head);

    node*root = DLLtoBST(&(obj3.head),10);

    cout<<"\nLevel Order traversal of the Merged BST : \n";
    levelOrder(root);
}