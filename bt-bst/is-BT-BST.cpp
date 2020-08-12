#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
struct validate
{
    bool isBST;
    int min = INT_MAX, max = INT_MIN;
};

node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

validate isBST(node*root)
{
    validate obj;
    if(root==NULL)
    {
        obj.isBST = true;
        return obj;
    }

    validate LV = isBST(root->left);
    validate RV = isBST(root->right);

    if(!LV.isBST || !RV.isBST || root->data <= LV.max || root->data >= RV.min)
    {
        obj.isBST = false;
        obj.max = max(root->data,RV.max);
        obj.min = min(root->data,LV.min);
        return obj;
    }
    else
    {
        obj.isBST = true;
        obj.min = min(LV.min,root->data);
        obj.max = max(RV.max,root->data);
        return obj;
    }
}

int main()
{
    struct node *root = newNode(12);
    root->left = newNode(5);
    root->right = newNode(15);
    // root->left->left = newNode(2);
    // root->left->right = newNode(8);
    root->right->left = newNode(15);
    root->right->right = newNode(16);
    // root->right->left->right = newNode(10);
    
    cout<<"Is BST ? "<<(isBST(root).isBST ? "Yes" : "No")<<endl;
}
