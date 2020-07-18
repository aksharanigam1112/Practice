// Minimum time to burn a Tree starting from a Leaf node
#include<iostream>
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int main()
{
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 

    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 

    root->left->left->left = newNode(8); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(10); 
    
    root->left->right->left->left = newNode(11); 
    
}