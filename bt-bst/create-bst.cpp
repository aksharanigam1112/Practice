#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node*left,*right;
};

node* newNode(int val)
{
    node*temp = new node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// node*insert(node*root,int val)
// {
    
//     if(root==NULL)
//     {
//         return newNode(val);
//     }
//     if(val > root->val)
//     {
//         root->right = insert(root->right,val);
//     }
//     if(val < root->val)
//     {
//         root->left = insert(root->left,val);
//     }
//     return root;
// }

node*insert(node*root,int val)
{   
    node*ptr = newNode(val);
    if(root==NULL)
        return ptr;
    
    node*temp = root,*prev = NULL;
    while(temp!=NULL)
    {
        prev = temp;
        if(val<temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(prev->val > ptr->val)
        prev->left = ptr;
    else
        prev->right = ptr;
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    struct node*root = new node;
    root = insert(root,8);
    root = insert(root,5);
    root = insert(root,18);
    inorder(root);
    
}