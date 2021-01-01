// Given a BT, print boundary nodes of the BT Anti-Clockwise starting from the root. 
// The boundary includes left boundary, leaves, and right boundary 
// in order without duplicate nodes. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node * newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
}

void printLeftBoundary(node*root)
{
    if(root==NULL)
        return ;
    
    if(root->left)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printLeafNodes(node*root)
{
    if(root==NULL)
        return ;
    
    printLeafNodes(root->left);

    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";
    
    printLeafNodes(root->right);
}

void printRightBoundary(node*root)
{
    if(root==NULL)
        return ;
    
    if(root->right)
    {
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }
}

void boundaryTraversal(node*root)
{
    if(root==NULL)
        return ;
    
    cout<<root->data<<" ";

    printLeftBoundary(root->left);

    printLeafNodes(root->left);
    printLeafNodes(root->right);

    printRightBoundary(root->right);
    cout<<endl;
}

int main()
{
    node* root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 

    root->left->left = newNode(4); 
    root->left->right = newNode(12);
    root->right->right = newNode(25); 

    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 

    cout<<"Boundary Traversal : ";
    boundaryTraversal(root);
}