// Prune a binary tree of the root-leaf path sum > k, delete all the nodes below
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int main()
{
    node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(2);

    
}