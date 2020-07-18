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
bool isBST(node*root,int lastVal)
{
    if(root==NULL)
        return true;
    bool LV = isBST(root->left,lastVal);
    if(!LV)
        return true;
    if(lastVal>root->data)
        return false;
    else
        lastVal = root->data;    
    return isBST(root->right,lastVal);
    
}

int main()
{
    struct node *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(2);
    // root->left->right = newNode(8);
    root->right->right = newNode(10);
    // root->right->left->right = newNode(10);
    int lastVal = INT_MIN;
    bool ans = isBST(root,lastVal);
    cout<<ans<<endl;
}
