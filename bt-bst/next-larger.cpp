// For the given number X, find the next largest or equal no. to X
#include<iostream>
#include<climits>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};

node *newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->right = n->left = NULL;
    return n;
}

int nextLarger(node *root, int X)
{
    if(root->left==NULL && root->right==NULL && root->data <X) 
        return -1; 
    
    if((root->data>=X && root->left==NULL)) 
        return root->data; 
    
    if (root->data <= X) 
        return nextLarger(root->right,X); 
  
    else
        return nextLarger(root->left, X); 
}

int main()
{
    node *root = newNode(20);
    root->left = newNode(15);
    root->right = newNode(40);

    root->left->left = newNode(10);
    root->left->right = newNode(18);
    root->right->left = newNode(30);
    root->right->right = newNode(55);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(12);

    root->right->left->left = newNode(25);
    root->right->left->right = newNode(36);

    cout<<"Next Larger or equal to X : "<<nextLarger(root,32)<<endl;
}