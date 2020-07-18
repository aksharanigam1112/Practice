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
int multLevel(node*root,int k,int curr)
{
    if(root==NULL)
        return 1;
    if(curr==k)
        return root->data;
    return multLevel(root->left,k,curr+1) * multLevel(root->right,k,curr+1);
}

int main()
{
    struct node *root = newNode(2);
    root->left = newNode(5);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    root->right->left = newNode(4);
    root->right->left->right = newNode(10);
    int ans = multLevel(root,3,1);
    cout<<ans<<endl;
}
