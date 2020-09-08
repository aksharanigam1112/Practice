// Given the root of a binary tree, value v & depth d, 
// you need to add a row of nodes with value v at the given depth d. 
// The root node is at depth 1. 
// original left subtree should be the left subtree of the new left subtree root, 
// its original right subtree should be the right subtree of the new right subtree root.
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
void print(node*root)
{
    if(root==NULL)
        return ;
    
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

node* addRow(node*root,int v, int d, int curr_depth)
{
    if(root==NULL)
        return root;
    
    if(d==1)
    {
        node* newroot = newNode(v);
        newroot->left = root;
        return newroot;
    }

    else if(curr_depth == d-1)
    {
        node* lv = root->left;
        node* rv = root->right;
        root->left = newNode(v);
        root->right = newNode(v);

        root->left->left = lv;
        root->right->right = rv;
        return root;
    }

    root->left = addRow(root->left,v,d,curr_depth+1);
    root->right = addRow(root->right,v,d,curr_depth+1);
    return root;
}

int main()
{
    node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);

    root->left->left = newNode(3);
    root->left->right = newNode(1);
    root->right->left = newNode(5);

    cout<<"Original tree : ";
    print(root);
    cout<<endl;

    node* newTree = addRow(root,1,3,1);
    cout<<"After adding row : ";
    print(newTree);
    cout<<endl;

}