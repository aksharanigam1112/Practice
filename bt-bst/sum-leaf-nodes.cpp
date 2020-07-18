#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}
bool isleaf(node*root)
{
    if(root==NULL)
        return false;
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

int sumLeaf(node*root)
{
    if(root==NULL)
        return 0;
    if(isleaf(root))
        return root->data;
    return sumLeaf(root->left)+sumLeaf(root->right);
} 
int main()
{
    struct node *root = newNode(2);
    root->left = newNode(5);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    root->right->left = newNode(4);
    int ans = sumLeaf(root);
    cout<<ans<<endl;
}
