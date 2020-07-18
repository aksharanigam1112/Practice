#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left,*right;
};

node* newNode(int val)
{
    node * ele = new node;
    ele->data = val;
    ele->left = ele->right = NULL;
    return ele;
}

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

    void printList(node *node) 
    { 
        while (node!=NULL) 
        { 
            cout<<node->data<<" "; 
            node = node->right; 
        }
        cout<<endl; 
    } 
};

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
    obj1.printList(obj1.head);

    INOP obj2 = INOP();    
    obj2.BSTtoDLL(root2);
    obj2.printList(obj2.head);
}